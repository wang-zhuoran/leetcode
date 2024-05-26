class Solution {
public:

    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long target){
        int sz = nums.size();

        vector<vector<int>> res;

        // 至少是2数之和，且数组大小不得小于n
        if(n < 2 || sz < n) return res;

        // base case: 2sum
        if(n == 2) {
            int left = start, right = sz - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                int tempLeft = nums[left], tempRight = nums[right];
                if(sum < target) {
                    while(left < right && nums[left] == tempLeft) left++;
                } else if (sum > target) {
                    while(left < right && nums[right] == tempRight) right--;
                }else{
                    res.push_back({tempLeft, tempRight});
                    while(left < right && nums[left] == tempLeft) left++;
                    while(left < right && nums[right] == tempRight) right--;
                }
            }
        }else{
            // n > 2时 递归计算（n-1）Sum的值
            for(int i = start; i < sz; i++){

                vector<vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);

                for(vector<int>& arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }

                while(i < sz - 1 && nums[i] == nums[i + 1]) i++;
            }
        }

        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        return nSumTarget(nums, 4, 0, target);
    }
};
