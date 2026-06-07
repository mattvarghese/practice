using Xunit;

namespace LeetCode.Tests;

public class TwoSumTests
{
    [Theory]
    // Exact test cases synchronized directly from your Python matrix
    [InlineData(new int[] { 2, 7, 11, 15 }, 9)]
    [InlineData(new int[] { 3, 2, 4 }, 6)]
    [InlineData(new int[] { 3, 3 }, 6)]
    [InlineData(new int[] { 1, 5, 5, 9 }, 10)]
    public void TestTwoSumImplementations(int[] nums, int target)
    {
        var result = TwoSum.Solve(nums, target);

        // 1. Verify that a result was actually returned (matches len() == 2)
        Assert.Equal(2, result.Length);

        // 2. Extract indices
        int idx1 = result[0];
        int idx2 = result[1];

        // 3. Ensure the indices are unique (cannot use the same element twice)
        Assert.NotEqual(idx1, idx2);

        // 4. Ensure indices are within the valid range of the array
        Assert.True(idx1 >= 0 && idx1 < nums.Length);
        Assert.True(idx2 >= 0 && idx2 < nums.Length);

        // 5. The core check: Do the values at these indices add up to the target?
        int actualSum = nums[idx1] + nums[idx2];
        Assert.Equal(target, actualSum);
    }
}