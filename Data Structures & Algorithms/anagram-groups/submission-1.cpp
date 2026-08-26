class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> sorted;

        for (const std::string &str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());

            sorted[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;

        for (auto &group : sorted) {
            result.push_back(group.second);
        }

        return result;
    }
};
