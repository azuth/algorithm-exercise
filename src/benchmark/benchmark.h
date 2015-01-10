#pragma once
#include <iostream>
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
    typedef std::vector<std::pair<std::string, std::vector<std::chrono::microseconds>>> benchmarkdata;

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


        /*
        int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                                 (end-start).count();

        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds << "s\n";*/

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
                {"Quicksort with Shiftoperator",Quicksort::withShiftoperator<T,S> }
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
                //std::cout << "    " << sf.first  << "-" << time.count() << std::endl;
                for(auto &a : arr.second){

                    if(a.first==sf.first){
                        a.second.push_back(time);
                    }
                }
                delete cp;
            }
        }
        std::cout << "-----------------------" << std::endl;

    }

    template<>
    void benchmarkIterator<double,0>(benchmarkdataset& data){

    }

    void writeCVS(benchmarkdata data){
        for(auto v :  data){
            std::cout  << v.first;
            for(auto time :  v.second){
                std::cout << "," << time.count();
            }
            std::cout  << std::endl;
        }
    }

    void benchmark(){
        const size_t iterations = 2;

        benchmarkdataset data;
        data.asc = {
                {"Insertionsort",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard And Early Decrement",std::vector<std::chrono::microseconds>()},
                {"Mergesort Bottom-Up",std::vector<std::chrono::microseconds>()},
                {"Mergesort Natural",std::vector<std::chrono::microseconds>()},
                {"Quicksort",std::vector<std::chrono::microseconds>()},
                {"Quicksort with Shiftoperator",std::vector<std::chrono::microseconds>() }
        };

        data.desc = {
                {"Insertionsort",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard And Early Decrement",std::vector<std::chrono::microseconds>()},
                {"Mergesort Bottom-Up",std::vector<std::chrono::microseconds>()},
                {"Mergesort Natural",std::vector<std::chrono::microseconds>()},
                {"Quicksort",std::vector<std::chrono::microseconds>()},
                {"Quicksort with Shiftoperator",std::vector<std::chrono::microseconds>() }
        };
        data.rand = {
                {"Insertionsort",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard",std::vector<std::chrono::microseconds>()},
                {"Insertionsort with Guard And Early Decrement",std::vector<std::chrono::microseconds>()},
                {"Mergesort Bottom-Up",std::vector<std::chrono::microseconds>()},
                {"Mergesort Natural",std::vector<std::chrono::microseconds>()},
                {"Quicksort",std::vector<std::chrono::microseconds>()},
                {"Quicksort with Shiftoperator",std::vector<std::chrono::microseconds>() }
        };
        benchmarkIterator<double,iterations>(data);
        writeCVS(data.asc);
        writeCVS(data.desc);
        writeCVS(data.rand);
    }

}







