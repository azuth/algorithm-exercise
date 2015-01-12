#pragma once
#include <array>

namespace Insertionsort{
    template <typename T, size_t SIZE>
    void normal(std::array<T,SIZE> &a){
        for(size_t i = 1 ; i < SIZE ; i++){
            T t = a[i];
            for(size_t j = i ; j > 0 && t < a[j-1]; j--){
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }

    template <typename T, size_t SIZE>
    void withGuard(std::array<T,SIZE> &a){
        size_t i,j;

        j = 0;
        for(i = 1 ; i < SIZE ; i++){
            if(a[j] > a[i]){
                j = i;
            }
        }
        std::swap(a[0],a[j]);

        for(i = 1 ; i < SIZE ; i++){
            T t = a[i];
            for(j = i ; t < a[j-1]; j--){
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }

    template <typename T, size_t SIZE>
    void withGuardAndEarlyDecrement(std::array<T,SIZE> &a){
        size_t i,j;

        j = 0;
        for(i = 1 ; i < SIZE ; i++){
            if(a[j] > a[i]){
                j = i;
            }
        }
        std::swap(a[0],a[j]);

        for(i = 1 ; i < SIZE ; i++){
            T t = a[i];
            for(j = i ; t < a[--j]; ){

                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    template <typename T, size_t SIZE>
    void sortBound(std::array<T,SIZE> &a,size_t leftBound,size_t rightBound){
        size_t i,j;

        j = leftBound;
        for(i = leftBound+1 ; i <= rightBound ; i++){
            if(a[j] > a[i]){
                j = i;
            }
        }
        std::swap(a[leftBound],a[j]);

        for(i = leftBound+1 ; i <= rightBound ; i++){
            T t = a[i];
            for(j = i ; t < a[--j]; ){

                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }


}
