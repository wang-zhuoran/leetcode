class Solution {
public:

    vector<vector<int>> twosum(vector<int>& nums, int start, int target) {
        int left = start, right = nums.size() - 1;
        vector<vector<int>> res;
        while(left < right) {
            int sum = nums[left] + nums[right];
            int tempLeft = nums[left], tempRight = nums[right];
            if(sum < target) {
                while(left < right && nums[left] == tempLeft) {
                    left++;
                }
            } else if(sum > target) {
                while(left < right && nums[right] == tempRight) {
                    right--;
                }
            } else {
                res.push_back({tempLeft, tempRight});
                while(left < right && nums[left] == tempLeft) left++;
                while(left < right && nums[right] == tempRight) right--;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> res;

        for(int i = 0; i < n; i++){
            vector<vector<int>> tuples = twosum(nums, i + 1, 0 - nums[i]);

            for(vector<int>& tuple: tuples) {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }

            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};
