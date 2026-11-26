package leetcode

// 1. Two Sum
// Easy - https://leetcode.com/problems/two-sum/
//
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// TwoSum finds two numbers in a slice that sum to a specific target using a one-pass map.
// Returns a two-element slice containing the indices, or nil if no solution exists.
func TwoSum(nums []int, target int) []int {
	// Maps value -> index
	seen := make(map[int]int, len(nums))

	for i, num := range nums {
		diff := target - num

		if idx, ok := seen[diff]; ok {
			return []int{idx, i}
		}
		seen[num] = i
	}

	return nil
}
