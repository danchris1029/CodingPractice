// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    
    // O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 3)
            return res;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i+1, right = nums.size()-1;
            while(left < right){
                if(nums[i]+nums[left]+nums[right] == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] == nums[left+1])
                       left++;
                    while(left<right && nums[right] == nums[right-1])
                       right--;
                    left++;
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right] < 0)
                    left++;
                else
                    right--;
            }
        }
        
        return res;
    }
};
