/**
 * 1. Two Sum
 * Easy - https://leetcode.com/problems/two-sum/
 * * Finds two numbers in an array that sum to a specific target using a one-pass Map.
 * * @param nums An array of integers.
 * @param target The integer sum to search for.
 * @returns An array containing the two indices, or an empty array if no solution exists.
 */
export function solve(nums: number[], target: number): number[] {
    // Maps value -> index
    const seen = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        const diff = target - nums[i];

        if (seen.has(diff)) {
            // map.get() is guaranteed to return a number here since seen.has() passed
            return [seen.get(diff)!, i];
        }
        seen.set(nums[i], i);
    }

    return [];
}
