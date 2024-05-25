class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while(left < right) {
            int maxHeight = min(height[left], height[right]);
            int temp = (right - left) * maxHeight;

            res = max(res, temp);

            if(height[left] <= height[right]){
                left++;
            } else{
                right--;
            }
        }

        return res;
    }
};
