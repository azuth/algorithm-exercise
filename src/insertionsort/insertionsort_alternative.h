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

    template <typename T, size_t SIZE>
    void withGuard(std::array<T,SIZE> &a){
        size_t i,j;

        j=0;
        for(i =0; i < SIZE; i++){
            if(a[j] > a[i])
                j=i;
        }
        if(j > 0){
            std::swap(a[0],a[j]);
        }

        for(i =1; i < SIZE; i++){
            j = i;
            T t = a[j];
            while(a[j-1] > t){
                a[j] = a[j-1];
                j--;
            }
            a[j] = t;
        }
    }

    template <typename T, size_t SIZE>
    void withGuardAndEarlyDecrement(std::array<T,SIZE> &a){
        size_t i,j;

        j=0;
        for(i =0; i < SIZE; i++){
            if(a[j] > a[i])
                j=i;
        }
        std::swap(a[0],a[j]);


        for(i =0; i < SIZE; i++){
            j = i;
            T t = a[j];
            while(a[--j] > t){
                a[j+1] = a[j];
            }
            a[j] = t;
        }
    }
}
