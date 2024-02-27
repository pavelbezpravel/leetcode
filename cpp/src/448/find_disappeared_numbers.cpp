// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

#include <utility>
#include <vector>

#include <gtest/gtest.h>

class Solution {
public:
    static std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        auto i = std::size_t{0};
        const auto size = nums.size();
        while (i < size) {
            if (const auto pos = static_cast<size_t>(nums[i]) - 1; nums[i] != nums[pos]) {
                std::swap(nums[i], nums[pos]);
            } else {
                ++i;
            }
        }

        std::vector<int> out{};
        out.reserve(size);

        for (int j = 0; const auto& num : nums) {
            if (num != j + 1) {
                out.push_back(j + 1);
            }
            ++j;
        }
        out.shrink_to_fit();
        return out;
    }
};

TEST(findDisappearedNumbers, example1) {
    auto nums = std::vector<int>{4, 3, 2, 7, 8, 2, 3, 1};
    const auto out = std::vector<int>{5, 6};
    EXPECT_EQ(Solution::findDisappearedNumbers(nums), out);
}

TEST(findDisappearedNumbers, example2) {
    auto nums = std::vector<int>{1, 1};
    const auto out = std::vector<int>{2};
    EXPECT_EQ(Solution::findDisappearedNumbers(nums), out);
}
