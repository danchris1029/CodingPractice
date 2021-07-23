// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        
        int l = -1, h = -1;
        bool leftDir = false;
        
        l = 0;
        int k = nums.size()/2;

        if(nums[k] < nums[0])
            leftDir = true;
        while(k > 0 && k < nums.size()-1 && nums[k] > nums[k-1]){
            if(leftDir)
                k--;
            else
                k++;
        }
        
        if(target == nums[0])
            return 0;
        else if(target == nums[nums.size()-1])
            return nums.size()-1;
        else if(target > nums[0]){
            h = k-1;
        }
        else if(target < nums[nums.size()-1]){
            l = k;
            h = nums.size()-1;
        }
        else
            return -1;
        
        //binary search this boi
        
        while(l <= h){
            if(nums[l] == target)
                return l;
            else
                l++;
            if(nums[h] == target)
                return h;
            else
                h--;
            
            k = l+((h-l)/2);
            if(nums[k] > target){
                h = k;
            }
            else if(nums[k] < target)
                l = k;
        }
        
        return -1;
    }
};
