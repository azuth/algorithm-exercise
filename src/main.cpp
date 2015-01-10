#include <iostream>
#include <array>
#include <string>
#include "benchmark/benchmark.h"


template <typename T, size_t SIZE>
void printArray(std::array<T,SIZE> &a){
    for(size_t i = 0; i < SIZE; i++ ){
        std::cout << a[i] << std::endl;
    }
}

int main()
{
     Benchmark::benchmark();

    return 0;
}

