class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (const std::string &str :strs) {
            std::size_t size = str.size();
            result += std::to_string(size);
            result += '#';
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int count = 0;
                while (s[i] != '#') {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }

                std::string word;

                for (int j = i + 1; j < i + 1 + count; j++) {
                    word += s[j];
                }

                result.push_back(word);

                i += count;
            }
        }

        return result;
    }
};
