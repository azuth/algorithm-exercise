#include <gtest/gtest.h>
#include <string>
#include "mergesort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Mergesort{

    TEST(Mergesort1, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        bottomUp(a);
        isSortet(a);
    }

    TEST(Mergesort1, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        bottomUp(a);
        isSortet(a);
    }

    TEST(Mergesort1, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        bottomUp(a);
        isSortet(a);
    }

    TEST(Mergesort1, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        bottomUp(a);
        isSortet(a);
    }

    TEST(Mergesort1, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        bottomUp(a);
        isSortet(a);
    }

    TEST(Mergesort1, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        bottomUp(a);
        isSortet(a);
    }
}
