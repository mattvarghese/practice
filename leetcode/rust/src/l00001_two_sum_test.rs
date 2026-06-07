use super::l00001_two_sum::Solution;

#[test]
fn test_two_sum_implementations() {
    // Exact test cases synchronized directly from your parameter matrix: (nums, target)
    let test_cases = vec![
        (vec![2, 7, 11, 15], 9),
        (vec![3, 2, 4], 6),
        (vec![3, 3], 6),
        (vec![1, 5, 5, 9], 10),
    ];

    for (nums, target) in test_cases {
        let result = Solution::two_sum(nums.clone(), target);

        // 1. Verify that a result was actually returned (matches len == 2)
        assert_eq!(result.len(), 2);

        // 2. Extract indices
        let idx1 = result[0] as usize;
        let idx2 = result[1] as usize;

        // 3. Ensure the indices are unique (cannot use the same element twice)
        assert_ne!(idx1, idx2);

        // 4. Ensure indices are within the valid range of the vector
        assert!(idx1 < nums.len());
        assert!(idx2 < nums.len());

        // 5. The core check: Do the values at these indices add up to the target?
        let actual_sum = nums[idx1] + nums[idx2];
        assert_eq!(actual_sum, target);
    }
}
