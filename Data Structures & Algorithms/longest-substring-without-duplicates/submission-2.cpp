class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;

        int longestLength = 0;

        std::unordered_set<char> seen;
        while (right < s.size()) {
            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            longestLength = std::max(longestLength, right - left + 1);
            right++;
        }

        return longestLength;
    }
};
