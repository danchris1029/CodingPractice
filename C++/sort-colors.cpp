class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int k = i+1; k < nums.size(); k++){
                if(nums[i] > nums[k]){
                    int temp = nums[i];
                    nums[i] = nums[k];
                    nums[k] = temp;
                }
            }
        }
    }
};