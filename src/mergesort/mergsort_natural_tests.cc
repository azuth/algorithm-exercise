#include <gtest/gtest.h>
#include <string>
#include "mergesort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Mergesort{

    TEST(Mergesort_natural, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        natural(a);
        isSortet(a);
    }

    TEST(Mergesort_natural, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        natural(a);
        isSortet(a);
    }

    TEST(Mergesort_natural, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        natural(a);
        isSortet(a);
    }

    TEST(Mergesort_natural, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        natural(a);
        isSortet(a);
    }

    TEST(Mergesort_natural, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        natural(a);
        isSortet(a);
    }

    TEST(Mergesort_natural, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        natural(a);
        isSortet(a);
    }
}