#include <gtest/gtest.h>
#include <string>
#include "quicksort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Quicksort{
    const size_t arraySize = 10;

    TEST(Quicksort_hybrid, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        hybrid(a);
        isSorted(a);
    }

    TEST(Quicksort_hybrid, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        hybrid(a);
        isSorted(a);
    }

    TEST(Quicksort_hybrid, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        hybrid(a);
        isSorted(a);
    }

    TEST(Quicksort_hybrid, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        hybrid(a);
        isSorted(a);
    }

    TEST(Quicksort_hybrid, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        hybrid(a);
        isSorted(a);
    }

    TEST(Quicksort_hybrid, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        hybrid(a);
        isSorted(a);
    }

}
