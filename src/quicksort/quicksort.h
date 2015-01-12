#pragma once
#include <iostream>
#include <array>
#include "../insertionsort/insertionsort.h"
#include "../mergesort/mergesort.h"

namespace Quicksort{
    template <typename T, size_t SIZE>

    template <typename T, size_t SIZE>
    void normalSort(std::array<T,SIZE> &a, size_t leftBound, size_t rightBound){
        if(rightBound <= leftBound){
            return;
        }

        size_t left = leftBound;
        size_t right = rightBound;

        size_t middle = (leftBound+rightBound)/2;
        T pivot = a[middle];
        std::swap(a[middle] , a[rightBound]);

        while(true){
            while( a[left] < pivot ){
                ++left;
            }

            while( pivot < a[--right] ){
                if(right == leftBound){
                    break;
                }
            }

            if( left >= right ){
                break;
            }
            std::swap(a[left] , a[right]);
        }
        std::swap(a[left] , a[rightBound]);

        if(left != 0){
            normalSort(a,leftBound,left-1);
        }

        normalSort(a,left+1,rightBound);
    }

    template <typename T, size_t SIZE>
    void normal(std::array<T,SIZE> &a){
        if (SIZE <= 1){
            return;
        }
        normalSort(a, 0, SIZE-1);
    }


    template <typename T, size_t SIZE>
    void withShiftoperatorSort(std::array<T,SIZE> &a, size_t leftBound, size_t rightBound){
        if(rightBound <= leftBound){
            return;
        }

        size_t left = leftBound;
        size_t right = rightBound;

        size_t middle = (leftBound+rightBound)>>1;
        T pivot = a[middle];
        std::swap(a[middle] , a[rightBound]);

        while(true){
            while( a[left] < pivot ){
                ++left;
            }

            while( pivot < a[--right] ){
                if(right == leftBound){
                    break;
                }
            }

            if( left >= right ){
                break;
            }
            std::swap(a[left] , a[right]);
        }
        std::swap(a[left] , a[rightBound]);

        if(left != 0){
            withShiftoperatorSort(a,leftBound,left-1);
        }

        withShiftoperatorSort(a,left+1,rightBound);
    }

    template <typename T, size_t SIZE>
    void withShiftoperator(std::array<T,SIZE> &a){
        if (SIZE <= 1){
            return;
        }
        withShiftoperatorSort(a, 0, SIZE-1);
    }


    template <typename T, size_t SIZE>
    void threeWayPartitioningSort(std::array<T,SIZE> &a, int leftBound, int rightBound){
        if(rightBound <= leftBound){
            return;
        }

        int left = leftBound-1;
        int right = rightBound;

        int pLeft = leftBound-1;
        int pRight = rightBound;

        int middle = (leftBound+rightBound)>>1;
        T pivot = a[middle];
        std::swap(a[middle] , a[rightBound]);


        while(true){
            while( a[++left] < pivot ){
                ;
            }

            while( pivot < a[--right] ){
                if(right == leftBound){
                    break;
                }
            }

            if(left >= right){
                break;
            }
            std::swap(a[left] , a[right]);

            if(a[left] == pivot){
                pLeft++;
                std::swap(a[pLeft] , a[left]);
            }

            if(pivot == a[right]){
                pRight--;
                std::swap(a[right] , a[pRight]);
            }
        }
        std::swap(a[left] , a[rightBound]);
        right = left-1;
        left = left +1;

        int k;
        for(k = leftBound ; k < pLeft ; k++,right--){
            std::swap(a[k] , a[right]);
        }

        for(k = rightBound-1 ; k > pRight ; k--, left++){
            std::swap(a[k] , a[left]);
        }

        threeWayPartitioningSort(a,leftBound,right);

        threeWayPartitioningSort(a,left,rightBound);
    }

    template <typename T, size_t SIZE>
    void threeWayPartitioning(std::array<T,SIZE> &a){
        if (SIZE <= 1){
            return;
        }
        threeWayPartitioningSort(a, 0, SIZE-1);
    }

    template <typename T, size_t SIZE>
    void hybridSort(std::array<T,SIZE> &a, int leftBound, int rightBound){
        if(rightBound-leftBound < 100){
            Insertionsort::sortBound(a,leftBound,rightBound);
        }else{
            if(rightBound <= leftBound){
                return;
            }

            int left = leftBound-1;
            int right = rightBound;

            int pLeft = leftBound-1;
            int pRight = rightBound;

            int middle = (leftBound+rightBound)>>1;
            T pivot = a[middle];
            std::swap(a[middle] , a[rightBound]);


            while(true){
                while( a[++left] < pivot ){
                    ;
                }

                while( pivot < a[--right] ){
                    if(right == leftBound){
                        break;
                    }
                }

                if(left >= right){
                    break;
                }
                std::swap(a[left] , a[right]);

                if(a[left] == pivot){
                    pLeft++;
                    std::swap(a[pLeft] , a[left]);
                }

                if(pivot == a[right]){
                    pRight--;
                    std::swap(a[right] , a[pRight]);
                }
            }
            std::swap(a[left] , a[rightBound]);
            right = left-1;
            left = left +1;

            int k;
            for(k = leftBound ; k < pLeft ; k++,right--){
                std::swap(a[k] , a[right]);
            }

            for(k = rightBound-1 ; k > pRight ; k--, left++){
                std::swap(a[k] , a[left]);
            }

            normalSort(a,leftBound,right);

            normalSort(a,left,rightBound);
        }
    }

    template <typename T, size_t SIZE>
    void hybrid(std::array<T,SIZE> &a){
        if (SIZE <= 1){
            return;
        }
        hybridSort(a, 0, SIZE-1);
    }
}


