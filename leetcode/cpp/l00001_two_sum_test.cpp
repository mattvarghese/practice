#define CATCH_CONFIG_MAIN // This tells Catch2 to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <vector>
#include <unordered_map>
#include <optional>
#include <utility>

// ============================================================================
// Implementation Under Test
// ============================================================================

std::optional<std::pair<int, int>> solve(const std::vector<int> &nums, int target)
{
    // Maps value -> index
    std::unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
        int diff = target - nums[i];

        // C++20/23 structured lookup: .find() remains standard for checking existence
        if (auto it = seen.find(diff); it != seen.end())
        {
            return std::make_pair(it->second, i);
        }
        seen[nums[i]] = i;
    }

    return std::nullopt; // Explicitly represents no solution found
}

// ============================================================================
// Catch2 Test Suite
// ============================================================================

TEST_CASE("Two Sum: LeetCode Example Cases", "[two_sum]")
{

    SECTION("Example 1: Classic matching pair")
    {
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        auto result = solve(nums, target);

        REQUIRE(result.has_value() == true);
        // Solution can be returned in any order, check both possibilities
        CHECK((result == std::make_pair(0, 1) || result == std::make_pair(1, 0)));
    }

    SECTION("Example 2: Indices are not adjacent")
    {
        std::vector<int> nums = {3, 2, 4};
        int target = 6;
        auto result = solve(nums, target);

        REQUIRE(result.has_value() == true);
        CHECK((result == std::make_pair(1, 2) || result == std::make_pair(2, 1)));
    }

    SECTION("Example 3: Identical values matching to target")
    {
        std::vector<int> nums = {3, 3};
        int target = 6;
        auto result = solve(nums, target);

        REQUIRE(result.has_value() == true);
        CHECK((result == std::make_pair(0, 1) || result == std::make_pair(1, 0)));
    }
}

TEST_CASE("Two Sum: Edge Cases and Negative Constraints", "[two_sum]")
{

    SECTION("Handling negative integers")
    {
        std::vector<int> nums = {-3, 4, 3, 90};
        int target = 0;
        auto result = solve(nums, target);

        REQUIRE(result.has_value() == true);
        CHECK((result == std::make_pair(0, 2) || result == std::make_pair(2, 0)));
    }

    SECTION("No matching target found")
    {
        std::vector<int> nums = {1, 2, 3};
        int target = 7;
        auto result = solve(nums, target);

        // Verifies std::nullopt optimization path
        CHECK(result.has_value() == false);
    }
}
