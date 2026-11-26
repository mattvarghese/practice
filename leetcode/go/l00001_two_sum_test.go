package leetcode

import "testing"

func TestTwoSum(t *testing.T) {
	// Exact test cases synchronized directly from the shared parameter matrix
	testCases := []struct {
		label  string
		nums   []int
		target int
	}{
		{label: "Example 1", nums: []int{2, 7, 11, 15}, target: 9},
		{label: "Example 2", nums: []int{3, 2, 4}, target: 6},
		{label: "Example 3", nums: []int{3, 3}, target: 6},
		{label: "Dual Pair Match", nums: []int{1, 5, 5, 9}, target: 10},
	}

	for _, tc := range testCases {
		t.Run(tc.label, func(t *testing.T) {
			result := TwoSum(tc.nums, tc.target)

			// 1. Verify that a result was actually returned (matches len() == 2)
			if len(result) != 2 {
				t.Fatalf("TwoSum(%v, %d) returned %v; want length 2", tc.nums, tc.target, result)
			}

			// 2. Extract indices
			idx1, idx2 := result[0], result[1]

			// 3. Ensure the indices are unique (cannot use the same element twice)
			if idx1 == idx2 {
				t.Fatalf("TwoSum(%v, %d) returned duplicate index %d", tc.nums, tc.target, idx1)
			}

			// 4. Ensure indices are within the valid range of the slice
			if idx1 < 0 || idx1 >= len(tc.nums) {
				t.Fatalf("idx1 = %d out of range [0, %d)", idx1, len(tc.nums))
			}
			if idx2 < 0 || idx2 >= len(tc.nums) {
				t.Fatalf("idx2 = %d out of range [0, %d)", idx2, len(tc.nums))
			}

			// 5. The core check: Do the values at these indices add up to the target?
			actualSum := tc.nums[idx1] + tc.nums[idx2]
			if actualSum != tc.target {
				t.Errorf("nums[%d] + nums[%d] = %d + %d = %d; want %d",
					idx1, idx2, tc.nums[idx1], tc.nums[idx2], actualSum, tc.target)
			}
		})
	}
}
