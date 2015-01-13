#include <gtest/gtest.h>
#include <string>
#include "mergesort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Mergesort{

    TEST(Mergesort_buttomUp, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, AscString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::ascArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, DescString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::descArray(a);
        bottomUp(a);
        isSorted(a);
    }

    TEST(Mergesort_buttomUp, RandomString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::randArray(a);
        bottomUp(a);
        isSorted(a);
    }
}
