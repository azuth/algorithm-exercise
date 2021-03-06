#include <gtest/gtest.h>
#include <string>
#include "insertionsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Insertionsort{

    TEST(Insertionsort_withGuardAndEarlyDecrement, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, AscString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::ascArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, DescString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::descArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }

    TEST(Insertionsort_withGuardAndEarlyDecrement, RandomString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::randArray(a);
        withGuardAndEarlyDecrement(a);
        isSorted(a);
    }
}
