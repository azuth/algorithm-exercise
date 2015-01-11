#include <gtest/gtest.h>
#include <string>
#include "quicksort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Quicksort{

    TEST(Quicksort_threeWayPartitioning, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }

    TEST(Quicksort_threeWayPartitioning, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }

    TEST(Quicksort_threeWayPartitioning, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }

    TEST(Quicksort_threeWayPartitioning, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }

    TEST(Quicksort_threeWayPartitioning, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }

    TEST(Quicksort_threeWayPartitioning, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        threeWayPartitioning(a);
        isSortet(a);
    }
}
