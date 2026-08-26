class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        std::vector<std::pair<int, int>> sorted(freq.begin(), freq.end());
        std::sort(
            sorted.begin(),
            sorted.end(),
            [](const std::pair<int, int> a, const std::pair<int, int> b) {
                return a.second > b.second; 
            }
        );

        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(sorted[i].first);
        }

        return result;
    }
};
