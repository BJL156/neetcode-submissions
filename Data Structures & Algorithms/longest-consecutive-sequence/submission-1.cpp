class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen;

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            seen.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i] - 1)) {
                continue;
            }

            int length = 1;
            int current = nums[i];
            while (seen.count(current + 1)) {
                length++;
                current++;
            }

            result = std::max(result, length);
        }

        return result;
    }
};
