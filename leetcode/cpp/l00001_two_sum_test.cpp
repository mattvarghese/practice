#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <vector>
#include <unordered_map>
#include <optional>
#include <utility>
#include <string>

// ============================================================================
// Implementation Under Test
// ============================================================================

std::optional<std::pair<int, int>> solve(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
        int diff = target - nums[i];

        if (auto it = seen.find(diff); it != seen.end())
        {
            return std::make_pair(it->second, i);
        }
        seen[nums[i]] = i;
    }

    return std::nullopt;
}

// ============================================================================
// Catch2 Test Suite (Synchronized with Python Cases)
// ============================================================================

struct TestData
{
    std::string label;
    std::vector<int> nums;
    int target;
};

TEST_CASE("Two Sum: Parameterized Invariant Validation", "[two_sum]")
{
    // Exact test cases synchronized directly from the Python matrix
    std::vector<TestData> test_matrix = {
        {"Example 1", {2, 7, 11, 15}, 9},
        {"Example 2", {3, 2, 4}, 6},
        {"Example 3", {3, 3}, 6},
        {"Dual Pair Match", {1, 5, 5, 9}, 10}};

    for (const auto &[label, nums, target] : test_matrix)
    {
        DYNAMIC_SECTION(label << " - Target: " << target)
        {
            auto result = solve(nums, target);

            // 1. Verify that a result was actually returned (has_value matches len() == 2)
            REQUIRE(result.has_value() == true);

            // 2. Extract indices
            auto [idx1, idx2] = result.value();

            // 3. Ensure the indices are unique (cannot use the same element twice)
            CHECK(idx1 != idx2);

            // 4. Ensure indices are within the valid range of the vector
            CHECK(idx1 >= 0);
            CHECK(idx1 < static_cast<int>(nums.size()));
            CHECK(idx2 >= 0);
            CHECK(idx2 < static_cast<int>(nums.size()));

            // 5. The core check: Do the values at these indices add up to the target?
            int actual_sum = nums[idx1] + nums[idx2];
            CHECK(actual_sum == target);
        }
    }
}
