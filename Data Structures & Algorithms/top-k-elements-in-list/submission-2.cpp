class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        std::vector<std::pair<int, int>> values(freq.begin(), freq.end());
        std::sort(
            values.begin(), values.end(),
            [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                return a.second > b.second;
            }
        );

        std::vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = values[i].first;
        }

        return result;
    }
};
