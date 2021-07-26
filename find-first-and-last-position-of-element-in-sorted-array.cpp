// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> indexs = {-1, -1};
        
        int foundIndex = -1;
        int l = 0,
            h = nums.size()-1;
        int m;
        while(l <= h){
            m = l+(h-l)/2;
            if(target == nums[m]){
                foundIndex = m;
                break;
            }
            if(target > nums[m])
                l = m+1;
            else
                h = m-1;
        }
        
        if(foundIndex != -1){
            int start = foundIndex,
                ending = foundIndex;
            int k = foundIndex-1;
            while(k >= 0 && nums[k] == nums[foundIndex]){
                start--;
                k--;
            }
            k = foundIndex+1;
            while(k < nums.size() && nums[k] == nums[foundIndex]){
                ending++;
                k++;
            }
            indexs[0] = start;
            indexs[1] = ending;
        }
        
        return indexs;
    }
};
