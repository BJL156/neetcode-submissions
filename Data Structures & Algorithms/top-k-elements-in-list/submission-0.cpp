class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;

        for (int &num : nums) {
            frequency[num]++;
        }

        std::vector<std::pair<int, int>> pairs;
        for (auto &num : frequency) {
            pairs.push_back({ num.first, num.second });
        }

        std::sort(
            pairs.begin(),
            pairs.end(),
            [](const auto &a, const auto &b) {
                return a.second > b.second;
            }
        );

        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pairs[i].first);
        }

        return result;
    }
};
