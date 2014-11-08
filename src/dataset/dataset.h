#include <cstdlib>
#include <iostream>
#include <ctime>

namespace Dataset{
    template <typename T, size_t SIZE>
    void generateArrays(    std::array<T,SIZE> &asc,
                            std::array<T,SIZE> &dsc,
                            std::array<T,SIZE> &rand){
        std::srand(std::time(0));
        for(size_t i =0; i < SIZE; i++){
            asc[i] = (T)i;
            dsc[SIZE-i-1] = (T)i;
            rand[i] = (T)std::rand();
        }
    }
}
