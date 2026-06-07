use std::collections::HashMap;

pub struct Solution;

impl Solution {
    /// Finds two numbers in a vector that sum to a specific target using a one-pass hash map.
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        // Maps value -> index
        let mut seen = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            let diff = target - num;

            if let Some(&index) = seen.get(&diff) {
                return vec![index as i32, i as i32];
            }
            seen.insert(num, i);
        }

        // Return empty vector if no match is found
        vec![]
    }
}