// Two pointer solution
// O(n^2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3)
            return nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        
        
        int closest = 10000;
        for(int i = 0; i < nums.size(); i++){
            for(int k = i+1, l = nums.size()-1; k < l;){
                int sum = nums[i] + nums[k] + nums[l];
              
                if(sum < target)
                    k++;
                else
                    l--;
                if(abs(sum-target) < abs(closest-target))
                    closest = sum;
            }
        }
        
        return closest;
    }
};
