#pragma once
#include <iostream>
#include <array>

namespace Mergesort{
    template <typename T, size_t SIZE>
    void printA(std::array<T,SIZE> &a){
        for(size_t i = 0 ; i < SIZE ; i++){
            std::cout << a[i];
        }
        std::cout << std::endl;
    }

    template <typename T, size_t SIZE>
    void merge(std::array<T,SIZE> &a, std::array<T,SIZE> &temp , size_t left , size_t middle , size_t end){

        size_t j = 0;
        size_t right = left;
        while( right < middle){
            temp[j] = a[right];
            j++;
            right++;
        }

        j = 0;
        size_t low  = left;
        while(j < middle-left  &&right < end ){
            if( a[right] < temp[j] ){
                a[low] = a[right];
                right++;
            }else{
                a[low] = temp[j];
                j++;
            }
            low++;
        }

        while( j < middle-left ){
            a[low] = temp[j];
            low++;
            j++;
        }
    }


    template <typename T, size_t SIZE>
    void bottomUp(std::array<T,SIZE> &a){
        std::array<T,SIZE>  temp;
        for(size_t width = 1 ; width < SIZE ; width = width << 1){
            for(size_t left = 0 ; left < SIZE ; left += width << 1){
                merge(a,temp, left, std::min(left+width,SIZE) , std::min(left+(width << 1),SIZE));
            }
        }
    }


}
