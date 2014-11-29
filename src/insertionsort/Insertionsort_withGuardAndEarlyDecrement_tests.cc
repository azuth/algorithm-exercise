#include <gtest/gtest.h>
#include <string>
#include "insertionsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Insertionsort{

    TEST(Insertionsort_withGuardAndEarlyDecrement, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        withGuardAndEarlyDecrement(a);
        isSortet(a);
    }
}
