namespace LeetCode;

public static class TwoSum
{
    /// <summary>
    /// Finds two numbers in an array that sum to a specific target using a one-pass dictionary map.
    /// </summary>
    public static int[] Solve(int[] nums, int target)
    {
        // Maps value -> index
        var seen = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int diff = target - nums[i];

            if (seen.TryGetValue(diff, out int index))
            {
                return new int[] { index, i };
            }
            seen[nums[i]] = i;
        }

        return Array.Empty<int>();
    }
}