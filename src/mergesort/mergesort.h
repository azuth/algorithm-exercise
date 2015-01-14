#pragma once
#include <array>
#include <memory>

namespace Mergesort{

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
        auto temp = std::make_shared<std::array<T,SIZE>>();
        for(size_t width = 1 ; width < SIZE ; width = width << 1){
            for(size_t left = 0 ; left < SIZE ; left += width << 1){
                merge(a,*temp.get(), left, std::min(left+width,SIZE) , std::min(left+(width << 1),SIZE));
            }
        }
    }



    template <typename T, size_t SIZE>
    void natural(std::array<T,SIZE> &a){
        auto temp = std::make_shared<std::array<T,SIZE>>();

        size_t left = 0;
        size_t end = SIZE-1;

        size_t l = left;
        size_t mid = left;
        size_t r = mid+1;
        bool unsorted = true;

        while(unsorted){
            mid = l;
            while(mid < end && a[mid] <= a[mid+1])
                mid++;


            r = mid +1;
            while(r < end && a[r] <= a[r+1])
                r++;


            if( l== 0 && mid+1 > end ){
                unsorted = false;
            }else{
                mid = std::min( mid+1,SIZE);
                r = std::min( r+1,SIZE);
                if(mid<r){     // mid >= r -> nothing to merge
                    merge(a,*temp.get(), l, mid , r); // to use the merge  mid+1 and r+1
                }
                l = r;

                if(l >= end)
                    l = 0;
            }
        }
    }

}
