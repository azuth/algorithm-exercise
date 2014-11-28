#pragma once
#include <array>

namespace Insertionsort{
    template <typename T, size_t SIZE>
    void normal(std::array<T,SIZE> &a){
        size_t i,j;
        for(i =0; i < SIZE; i++){
            j = i;
            T t = a[j];
            while(j > 0 && a[j-1] > t){
                a[j] = a[j-1];
                j--;
            }
            a[j] = t;
        }
    }
}
