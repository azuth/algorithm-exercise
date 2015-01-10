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

    template <typename T, size_t S>
    auto stoptime(std::function<void(std::array<T,S>&)> f, std::array<T,S> &a)
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;

        // fehlt -> mit zufallszahlen überschreiben

        start = std::chrono::system_clock::now();
        f(a);
        end = std::chrono::system_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); // nanoseconds



        int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                                 (end-start).count();

        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds << "s\n";

    }


    template <typename T, size_t I>
    void benchmarkIterator()
    {

        benchmarkIterator<T,I-1>();
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

        std::vector<std::pair<std::string, std::array<T ,S>>> arrays;
        arrays = {  {"Asc",aAsc},
                    {"Desc",aDesc},
                    {"Rand",aRand}
        };

        std::cout << "Size: " << S << std::endl;
        for(auto sf : sfv){
            for(auto arr :  arrays){
                auto cp = new std::array<T, S>(arr.second);
                std::cout << sf.first << "-" << arr.first << "-" <<stoptime(sf.second,*cp) << std:: endl;
                delete cp;
            }
        }


    }

    template<>
    void benchmarkIterator<double,0>(){
    }

    void benchmark(){
        const size_t iterations = 4;
        benchmarkIterator<double,iterations>();
    }


}







