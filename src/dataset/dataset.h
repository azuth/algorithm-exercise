#include <cstdlib>
#include <iostream>
#include <ctime>

namespace Dataset{
    template <typename T, size_t SIZE>
    void ascArray(std::array<T,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            a[i] = (T)i;
        }
    }

    template <typename T, size_t SIZE>
    void descArray(std::array<T,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            a[SIZE-i-1] = (T)i;
        }
    }

    template <typename T, size_t SIZE>
    void randArray(std::array<T,SIZE> &a){
        std::srand(std::time(0));
        for(size_t i =0; i < SIZE; i++){
            a[i] = (T)std::rand();
        }
    }

}
