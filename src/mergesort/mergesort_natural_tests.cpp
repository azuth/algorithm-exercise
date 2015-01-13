#include <gtest/gtest.h>
#include <string>
#include "mergesort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Mergesort{

    TEST(Mergesort_natural, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, AscString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::ascArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, DescString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::descArray(a);
        natural(a);
        isSorted(a);
    }

    TEST(Mergesort_natural, RandomString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::randArray(a);
        natural(a);
        isSorted(a);
    }
}
