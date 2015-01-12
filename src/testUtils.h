#include <gtest/gtest.h>
#include <array>

const size_t arraySize = 999;

template <typename T, size_t SIZE>
void isSortet(std::array<T,SIZE> &a){
    for(size_t i = 0; i < SIZE-1 ; i++ ){
        EXPECT_LE(a[i], a[i+1]);
    }
}



