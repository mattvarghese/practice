import { solve } from './l00001_two_sum';

describe('Two Sum: Parameterized Invariant Validation', () => {
    // Exact test cases synchronized directly from your Python matrix
    const testMatrix = [
        { label: 'Example 1', nums: [2, 7, 11, 15], target: 9 },
        { label: 'Example 2', nums: [3, 2, 4], target: 6 },
        { label: 'Example 3', nums: [3, 3], target: 6 },
        { label: 'Dual Pair Match', nums: [1, 5, 5, 9], target: 10 },
    ];

    test.each(testMatrix)(
        '$label - Target: $target',
        ({ nums, target }) => {
            const result = solve(nums, target);

            // 1. Verify that a result was actually returned (matches len() == 2)
            expect(result).toHaveLength(2);

            // 2. Extract indices
            const [idx1, idx2] = result;

            // 3. Ensure the indices are unique (cannot use the same element twice)
            expect(idx1).not.toBe(idx2);

            // 4. Ensure indices are within the valid range of the array
            expect(idx1).toBeGreaterThanOrEqual(0);
            expect(idx1).toBeLessThan(nums.length);
            expect(idx2).toBeGreaterThanOrEqual(0);
            expect(idx2).toBeLessThan(nums.length);

            // 5. The core check: Do the values at these indices add up to the target?
            const actualSum = nums[idx1] + nums[idx2];
            expect(actualSum).toBe(target);
        }
    );
});
