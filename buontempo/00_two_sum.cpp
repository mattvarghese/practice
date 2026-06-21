#include <vector>
#include <unordered_map>
#include <optional>
#include <utility>

// This is leetcode problem #1 - Two Sum
// Easy - https://leetcode.com/problems/two-sum/

// Including this here so we can setup our CMakeLists.txt etc.
// before we go into actual code from the book

std::optional<std::pair<int, int>> solve(const std::vector<int> &nums, int target)
{
    // Maps value -> index
    std::unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
        int diff = target - nums[i];

        // C++20/23 structured lookup: .find() remains standard for checking existence
        if (auto it = seen.find(diff); it != seen.end())
        {
            return std::make_pair(it->second, i);
        }
        seen[nums[i]] = i;
    }

    return std::nullopt; // Explicitly represents no solution found
}
