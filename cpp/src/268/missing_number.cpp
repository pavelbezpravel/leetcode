// https://leetcode.com/problems/missing-number

#include <numeric>
#include <vector>

#include <gtest/gtest.h>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        return size * (size + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};

TEST(missingNumber, example1) {
    auto nums = std::vector<int>{3, 0, 1};
    EXPECT_EQ(Solution().missingNumber(nums), 2);
}

TEST(missingNumber, example2) {
    auto nums = std::vector<int>{0, 1};
    EXPECT_EQ(Solution().missingNumber(nums), 2);
}

TEST(missingNumber, example3) {
    auto nums = std::vector<int>{9, 6, 4, 2, 3, 5, 7, 0, 1};
    EXPECT_EQ(Solution().missingNumber(nums), 8);
}
