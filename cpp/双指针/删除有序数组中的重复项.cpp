class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num_size = nums.size();
        if(num_size == 0) {
            return 0;
        }

        int slow = 1, fast = 1;

        while(fast < num_size){
            if(nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};
