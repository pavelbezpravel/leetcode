// https://leetcode.com/problems/contains-duplicate

#include <set>
#include <vector>

#include <gtest/gtest.h>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> seen{};
        for (const auto& num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.emplace(num);
        }
        return false;
    }
};

TEST(containsDuplicate, example1) {
    auto nums = std::vector<int>{1, 2, 3, 1};
    EXPECT_EQ(Solution().containsDuplicate(nums), true);
}

TEST(containsDuplicate, example2) {
    auto nums = std::vector<int>{1, 2, 3, 4};
    EXPECT_EQ(Solution().containsDuplicate(nums), false);
}

TEST(containsDuplicate, example3) {
    auto nums = std::vector<int>{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_EQ(Solution().containsDuplicate(nums), true);
}
