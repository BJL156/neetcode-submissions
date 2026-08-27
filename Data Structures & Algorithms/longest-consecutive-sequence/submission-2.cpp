class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());

        int longestLength = 0;
        for (int num : seen) {
            if (!seen.contains(num - 1)) {
                int length = 1;
                int current = num;
                while (seen.contains(current + 1)) {
                    length++;
                    current++;
                }

                if (longestLength < length) {
                    longestLength = length;
                }
            }
        }

        return longestLength;
    }
};
