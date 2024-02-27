// https://leetcode.com/problems/single-number

#include <vector>

#include <gtest/gtest.h>

class Solution {
public:
    static int singleNumber(const std::vector<int>& nums) {
        int mask = 0;
        for (const auto& num : nums) {
            mask ^= num;
        }
        return mask;
    }
};

TEST(singleNumber, example1) {
    const auto nums = std::vector<int>{2, 2, 1};
    EXPECT_EQ(Solution::singleNumber(nums), 1);
}

TEST(singleNumber, example2) {
    const auto nums = std::vector<int>{4, 1, 2, 1, 2};
    EXPECT_EQ(Solution::singleNumber(nums), 4);
}

TEST(singleNumber, example3) {
    const auto nums = std::vector<int>{1};
    EXPECT_EQ(Solution::singleNumber(nums), 1);
}
