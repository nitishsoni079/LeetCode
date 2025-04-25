class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;

        // Iterate through the input vector `nums` along with the index
        for (int i = 0; i < nums.size(); ++i) {
            int current_num = nums[i];
            int complement = target - current_num;

            // Check if the complement needed to reach the target exists in the map
            // num_map.count(complement) returns 1 if the key exists, 0 otherwise.
            if (num_map.count(complement)) {
                // If the complement exists, we found the pair!
                // Return the index of the complement (stored in the map)
                // and the index of the current number.
                // Note: Using curly braces {} initializes and returns a vector.
                return {num_map[complement], i};
            }

            // If the complement was not found, add the current number and its index
            // to the map. This prepares it for potential future matches.
            // If the number already exists as a key, its index value will be updated.
            num_map[current_num] = i;
        }

        // If the loop completes without finding a solution (the problem statement
        // usually guarantees one exists, but handling this case is robust).
        // LeetCode expects a return value, so returning an empty vector is common,
        // though throwing an exception might be appropriate in other contexts.
        return {};
        // Alternatively, you could throw an exception:
        // throw std::runtime_error("No two sum solution found");
    }
};
    
