#include <gtest/gtest.h>
#include <string>
#include "quicksort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Quicksort{

    TEST(Quicksort_withShiftoperator, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

    TEST(Quicksort_withShiftoperator, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

    TEST(Quicksort_withShiftoperator, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

    TEST(Quicksort_withShiftoperator, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

    TEST(Quicksort_withShiftoperator, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

    TEST(Quicksort_withShiftoperator, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        withShiftoperator(a);
        isSortet(a);
    }

}
