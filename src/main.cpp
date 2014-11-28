#include <iostream>
#include <array>
#include <string>
#include "dataset/dataset.h"
#include "insertionsort/insertionsort.h"


template <typename T, size_t SIZE>
void printArray(std::array<T,SIZE> &a){
    for(size_t i = 0; i < SIZE; i++ ){
        std::cout << a[i] << std::endl;
    }
}




int main()
{
    const size_t l = 1000;
    std::array<double ,l> aAsc,aDesc,aRand;
    Dataset::ascArray(aAsc);
    Dataset::descArray(aDesc);
    Dataset::randArray(aRand);

    Insertionsort::normal(aAsc);
    Insertionsort::normal(aDesc);
    Insertionsort::normal(aRand);


    std::cout << "double asc" << std::endl;
    printArray(aAsc);

    std::cout << "double desc" << std::endl;
    printArray(aDesc);

    std::cout << "double rand" << std::endl;
    printArray(aRand);



    return 0;
}

