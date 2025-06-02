#include "gtest/gtest.h"
#include "functions.h"

TEST(FunctionsTest, FindMinMax) {
    std::vector<int> arr = { 10, 20, 5, 30, 15 };
    int min, max;
    findMinMax(arr, min, max);
    EXPECT_EQ(min, 5);
    EXPECT_EQ(max, 30);
}

TEST(FunctionsTest, ComputeAverage) {
    std::vector<int> arr = { 10, 20, 5, 30, 15 };
    double avg = computeAverage(arr);
    EXPECT_DOUBLE_EQ(avg, 16.0);
}

TEST(FunctionsTest, ReplaceMinMax) {
    std::vector<int> arr = { 10, 20, 5, 30, 15 };
    replaceMinMax(arr, 5, 30, 16.0);
    std::vector<int> expected = { 10, 20, 16, 16, 15 };
    EXPECT_EQ(arr, expected);
}
