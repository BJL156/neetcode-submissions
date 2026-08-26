class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        
        for (std::string str : strs) {
            char count[26] = { 0 };

            for (char c : str) {
                count[c - 'a']++;
            }

            std::string key = "";
            for (int i = 0; i < 26; i++) {
                key += '#' + std::to_string(count[i]);
            }

            mp[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
