class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        
        int result = 0;
        while (left < right) {
            int width = right - left;

            int height = 0;
            if (heights[left] < heights[right]) {
                height = heights[left];
                left++;
            } else {
                height = heights[right];
                right--;
            }

            result = std::max(result, width * height);
        }

        return result;
    }
};
