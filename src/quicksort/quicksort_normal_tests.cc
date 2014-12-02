#include <gtest/gtest.h>
#include <string>
#include "quicksort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Quicksort{

    TEST(Quicksort_normal, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Quicksort_normal, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Quicksort_normal, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Quicksort_normal, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Quicksort_normal, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Quicksort_normal, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSortet(a);
    }

}
