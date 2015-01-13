#pragma once
#include <random>
#include <vector>

namespace Dataset{
    template <typename T, size_t SIZE>
    void ascArray(std::array<T,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            a[i] = static_cast<T>(i);
        }
    }

    template <size_t SIZE>
    void ascArray(std::array<std::string,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            std::string s;
            s.reserve(i);
            for(size_t j= 0; j < i; j++){
                s.append("x");
            }
            a[i] = s;
        }
    }

    template <typename T, size_t SIZE>
    void descArray(std::array<T,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            a[SIZE-i-1] = static_cast<T>(i);
        }
    }

    template <size_t SIZE>
    void descArray(std::array<std::string,SIZE> &a){
        for(size_t i =0; i < SIZE; i++){
            std::string s;
            s.reserve(i);
            for(size_t j= 0; j < i; j++){
                s.append("x");
            }
            a[SIZE-i-1] = s;
        }
    }

    template <typename T, size_t SIZE>
    void randArray(std::array<T,SIZE> &a){

        std::random_device rd;
        std::mt19937 gen(rd());
        std:: uniform_real_distribution<> randReal(0,SIZE);

        for(size_t i =0; i < SIZE; i++){
            a[i] = static_cast<T>(randReal(gen));
        }
    }

    template <size_t SIZE>
    void randArray(std::array<std::string,SIZE> &a){
         const std::vector<char> charset = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std:: uniform_int_distribution<> randChar(0,charset.size()-1);
        std:: uniform_int_distribution<> randWordlenght(0,25);

        for(size_t i =0; i < SIZE; i++){
            auto wordlenght = randWordlenght(gen);
            std::string s;
            s.reserve(wordlenght);
            for(size_t j= 0; j < wordlenght; j++){
                s.push_back(charset.at(randChar(gen)));
            }
            a[i] = s;
        }
    }


}
