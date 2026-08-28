class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> monoSt;

        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {
            int currentHeight = (i == heights.size()) ? 0 : heights[i];

            while (!monoSt.empty() && heights[monoSt.top()] > currentHeight) {
                int height = heights[monoSt.top()];
                monoSt.pop();

                int width = 0;
                if (monoSt.empty()) {
                    width = i;
                } else {
                    width = i - monoSt.top() - 1;
                }

                maxArea = std::max(maxArea, height * width);
            }

            monoSt.push(i);
        }

        return maxArea;
    }
};
