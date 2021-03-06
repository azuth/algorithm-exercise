#include <gtest/gtest.h>
#include <string>
#include "heapsort.h"
#include "../dataset/dataset.h"
#include "../testUtils.h"


namespace Heapsort{

    TEST(Heapsort_normal, AscInt)
    {
        std::array<int ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, DescInt)
    {
        std::array<int ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, RandomInt)
    {
        std::array<int ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, AscDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, DescDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, RandomDouble)
    {
        std::array<double ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSorted(a);
    }


    TEST(Heapsort_normal, AscString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::ascArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, DescString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::descArray(a);
        normal(a);
        isSorted(a);
    }

    TEST(Heapsort_normal, RandomString)
    {
        std::array<std::string ,arraySize> a;
        Dataset::randArray(a);
        normal(a);
        isSorted(a);
    }
}
