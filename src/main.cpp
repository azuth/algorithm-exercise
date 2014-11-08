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
    std::array<int ,l> ai1,ai2,ai3;
    Dataset::generateArrays(ai1,ai2,ai3);

    std::array<double, l> ad1,ad2,ad3;
    Dataset::generateArrays(ad1,ad2,ad3);

    std::array<std::string ,3> e = {"blah","foo","bar"};

    Insertionsort::sortVersion1(ai1);
    Insertionsort::sortVersion1(ai1);
    Insertionsort::sortVersion1(ai1);
    Insertionsort::sortVersion1(ad1);
    Insertionsort::sortVersion1(ad2);
    Insertionsort::sortVersion1(ad3);
    Insertionsort::sortVersion1(e);

    std::cout << "asc" << std::endl;
    printArray(ai1);


    std::cout << "desc" << std::endl;
    printArray(ai2);

    std::cout << "rand" << std::endl;
    printArray(ai3);

    std::cout << "double asc" << std::endl;
    printArray(ad1);

    std::cout << "double desc" << std::endl;
    printArray(ad2);

    std::cout << "double rand" << std::endl;
    printArray(ad3);

    std::cout << "string" << std::endl;
    printArray(e);

    return 0;
}
