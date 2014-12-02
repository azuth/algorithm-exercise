#pragma once
#include <iostream>
#include <array>

namespace Quicksort{
    template <typename T, size_t SIZE>
    void printArray(std::array<T,SIZE> &a){
        for(size_t i = 0; i < SIZE; i++ ){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T, size_t SIZE>
    void normalSort(std::array<T,SIZE> &a, size_t leftBound, size_t rightBound){
        size_t left = leftBound;
        size_t right = rightBound;
        T pivot = a[(leftBound+rightBound)/2];

        while(left <= right){
            while( a[left] < pivot )
                ++left;
            while( pivot < a[right] ){
                --right;
            }

            if( left <= right ){
                std::swap(a[left] , a[right]);

                ++left;
                if(right  > 0){
                    --right;
                }
            }
        }

        if(leftBound < right){
            normalSort(a,leftBound,right);
        }

        if(left < rightBound){
            normalSort(a,left,rightBound);
        }
    }

    template <typename T, size_t SIZE>
    void normal(std::array<T,SIZE> &a){
        if (SIZE <= 1){
            return;
        }
        normalSort(a, 0, SIZE-1);
    }



}
