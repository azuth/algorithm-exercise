#pragma once
#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <chrono>
#include "../dataset/dataset.h"
#include "../insertionsort/insertionsort.h"
#include "../mergesort/mergesort.h"
#include "../quicksort/quicksort.h"
#include "../heapsort/heapsort.h"

namespace Benchmark{
    typedef std::map<std::string, std::vector<std::chrono::microseconds>> benchmarkdata;

    struct benchmarkdataset{
            benchmarkdata asc,desc,rand;
    };

    template <typename T, size_t S>
    std::chrono::microseconds stoptime(std::function<void(std::array<T,S>&)> f, std::array<T,S> &a)
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;

        // fehlt -> mit zufallszahlen überschreiben

        start = std::chrono::system_clock::now();
        f(a);
        end = std::chrono::system_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end-start); // nanoseconds
    }


    template <typename T, size_t I>
    void benchmarkIterator(benchmarkdataset& data)
    {
        benchmarkIterator<T,I-1>(data);
        const size_t S = 10000 * (1 << (I - 1));


        std::vector<std::pair<std::string, std::function<void(std::array<T,S>&)>>> sfv;
        sfv= {  {"Insertionsort",Insertionsort::normal<T,S>},
                {"Insertionsort with Guard",Insertionsort::withGuard<T,S>},
                {"Insertionsort with Guard And Early Decrement",Insertionsort::withGuardAndEarlyDecrement<T,S>},
                {"Mergesort Bottom-Up",Mergesort::bottomUp<T,S>},
                {"Mergesort Natural",Mergesort::natural<T,S>},
                {"Quicksort",Quicksort::normal<T,S>},
                {"Quicksort with Shiftoperator",Quicksort::withShiftoperator<T,S>},
                {"Heapsort",Heapsort::normal<T,S>}
        };

        std::array<T ,S> aAsc,aDesc,aRand;
        Dataset::ascArray(aAsc);
        Dataset::descArray(aDesc);
        Dataset::randArray(aRand);

        std::vector<
            std::pair<std::array<T ,S>,benchmarkdata& >>arrays;
        arrays = {  {aAsc,data.asc},
                    {aDesc,data.desc},
                    {aRand,data.rand}
        };

        std::cout << "Array Size: " << S << std::endl;
        for(auto &arr :  arrays){
            //std::cout << "Array Type: " << arr.first <<  std:: endl;
            for(auto sf : sfv){
                auto cp = new std::array<T, S>(arr.first);
                auto time = stoptime(sf.second,*cp);
                std::cout << "    " << sf.first  << ": " << time.count() << std::endl;
                arr.second[sf.first].push_back(time);
                delete cp;
            }
        }
        std::cout << "-----------------------" << std::endl;

    }

    template<>
    void benchmarkIterator<double,0>(benchmarkdataset& data){

    }

    void writeDataToCVS(std::ostream& stream,benchmarkdata data,size_t iterations){
        stream  << "Array Size";
        for(size_t i = 1; i <= iterations ; i++ ){
            stream << "," << i* 10000;
        }
        stream  << std::endl;

        for(auto v :  data){
            stream  << v.first;
            for(auto time :  v.second){
                stream << "," << time.count();
            }
            stream  << std::endl;
        }
    }

    void makeCVS(benchmarkdataset data,size_t iterations){
        std::ofstream asc("asc.csv");
        asc << "Ascending" << std::endl;
        writeDataToCVS(asc,data.asc,iterations);
        asc.close();

        std::ofstream desc ("desc.csv");
        desc << "Descending"<< std::endl;
        writeDataToCVS(desc,data.desc,iterations);
        desc.close();

        std::ofstream rand ("rand.csv");
        rand << "Random"<< std::endl;
        writeDataToCVS(rand,data.rand,iterations);
        rand.close();
    }

    void benchmark(){
        const size_t iterations = 4;
        benchmarkdataset data;
        benchmarkIterator<double,iterations>(data);
        makeCVS(data,iterations);
    }

}







