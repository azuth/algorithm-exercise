#include <gtest/gtest.h>
#include <string>
#include "insertionsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Insertionsort{

    TEST(Insertionsort_sortBound, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }

    TEST(Insertionsort_sortBound, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }

    TEST(Insertionsort_sortBound, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }

    TEST(Insertionsort_sortBound, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }

    TEST(Insertionsort_sortBound, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }

    TEST(Insertionsort_sortBound, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        sortBound(a,0,arraySize-1);
        isSorted(a);
    }
}
