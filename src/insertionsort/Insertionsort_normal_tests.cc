#include <gtest/gtest.h>
#include <string>
#include "insertionsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.cc"


namespace Insertionsort{

    TEST(Insertionsort_normal, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Insertionsort_normal, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Insertionsort_normal, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Insertionsort_normal, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Insertionsort_normal, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSortet(a);
    }

    TEST(Insertionsort_normal, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSortet(a);
    }
}
