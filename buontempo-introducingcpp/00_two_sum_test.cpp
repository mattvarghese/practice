#include <gtest/gtest.h>
#include <vector>
#include <optional>
#include <utility>
#include <algorithm>

// Forward declaration of your logic method from 00_two_sum.cpp
std::optional<std::pair<int, int>> solve(const std::vector<int> &nums, int target);

// Define a structured layout for our data matrix inputs
struct TwoSumTestCase
{
    std::string label;
    std::vector<int> nums;
    int target;
};

// Create a fixture class inheriting from GoogleTest's Parameterized Test suite
class TwoSumParameterizedTest : public ::testing::TestWithParam<TwoSumTestCase>
{
};

// The concrete test block executing against the parameter streams
TEST_P(TwoSumParameterizedTest, InvariantValidation)
{
    // Extract the active case configuration values from the stream
    const auto &[label, nums, target] = GetParam();

    // Execute your single-pass map logic
    auto result = solve(nums, target);

    // 1. Core invariant: Verify that an optional pair was actually returned
    ASSERT_TRUE(result.has_value())
        << "Failed for " << label << ": Expected a valid index pair.";

    auto [idx1, idx2] = result.value();

    // 2. Bound checks: Ensure indices are completely unique and within vector memory boundaries
    ASSERT_NE(idx1, idx2)
        << "Failed for " << label << ": Indices must be distinct.";
    ASSERT_GE(idx1, 0);
    ASSERT_LT(idx1, static_cast<int>(nums.size()));
    ASSERT_GE(idx2, 0);
    ASSERT_LT(idx2, static_cast<int>(nums.size()));

    // 3. Mathematical truth check: Do the values add up to your targeted sum?
    int actual_sum = nums[idx1] + nums[idx2];
    EXPECT_EQ(actual_sum, target)
        << "Failed for " << label << ": " << nums[idx1] << " + " << nums[idx2] << " != " << target;
}

// Instantiate the complete collection of matrices directly from your specifications
INSTANTIATE_TEST_SUITE_P(
    LeetCodeExamples,
    TwoSumParameterizedTest,
    ::testing::Values(
        TwoSumTestCase{"Example 1", {2, 7, 11, 15}, 9},
        TwoSumTestCase{"Example 2", {3, 2, 4}, 6},
        TwoSumTestCase{"Example 3", {3, 3}, 6},
        TwoSumTestCase{"Dual Pair Match", {1, 5, 5, 9}, 10}),
    [](const ::testing::TestParamInfo<TwoSumTestCase> &test_info)
    {
        // Formats test runner output strings into human-readable labels
        std::string name = test_info.param.label;
        std::replace(name.begin(), name.end(), ' ', '_');
        return name;
    });
