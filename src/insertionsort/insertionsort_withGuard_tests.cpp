#include <gtest/gtest.h>
#include <string>
#include "insertionsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Insertionsort{

    TEST(Insertionsort_withGuard, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        withGuard(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuard, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        withGuard(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuard, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        withGuard(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuard, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        withGuard(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuard, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        withGuard(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuard, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        withGuard(a);
        isSortet(a);
    }
}
