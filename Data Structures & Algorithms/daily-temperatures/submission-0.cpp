class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);

        std::stack<int> monoSt;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!monoSt.empty() &&
                    temperatures[i] > temperatures[monoSt.top()]) {
                int prev = monoSt.top();
                monoSt.pop();
                result[prev] = i - prev;
            }

            monoSt.push(i);
        }

        return result;
    }
};
