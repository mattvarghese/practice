# 1. Two Sum
# Easy - https://leetcode.com/problems/two-sum/

# Given an array of integers nums and an integer target,
# return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]

# Constraints:
# 2 <= nums.length <= 104
# -109 <= nums[i] <= 109
# -109 <= target <= 109
# Only one valid answer exists.

# Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


def solve(nums, target):
    """
    Finds two numbers in an array that sum to a specific target using a one-pass hash map.

    This is the most time-efficient approach as it resolves the complement
    and the self-matching constraint in a single traversal.

    Args:
        nums (list[int]): A list of integers.
        target (int): The integer sum to search for.

    Returns:
        tuple[int, int] | tuple[]: The indices of the two numbers that add up to target,
                                   or an empty tuple if no solution exists.
    """
    seen = {}  # val : index
    for i, num in enumerate(nums):
        diff = target - num
        if diff in seen:
            return (seen[diff], i)
        seen[num] = i
    return ()


def solve2(nums, target):
    """
    Finds two numbers that sum to target using a two-pass grouping strategy.

    Maps each unique value to a list of its indices to handle duplicate
    values explicitly.

    Args:
        nums (list[int]): A list of integers.
        target (int): The integer sum to search for.

    Returns:
        tuple[int, int] | tuple[]: The indices of the two numbers,
                                   or an empty tuple if not found.
    """
    # Using 'index_map' instead of 'map' to avoid shadowing built-in functions
    index_map = {}
    for i, num in enumerate(nums):
        if num in index_map:
            index_map[num].append(i)
        else:
            index_map[num] = [i]

    for num, indices in index_map.items():
        diff = target - num
        if (diff == num) and (len(index_map[num]) > 1):
            return (indices[0], indices[1])
        elif (diff != num) and (diff in index_map):
            return (indices[0], index_map[diff][0])
    return ()
