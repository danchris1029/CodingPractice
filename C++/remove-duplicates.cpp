// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int openPointer = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i])
                nums[openPointer++] = nums[i];
        }
        return openPointer;
    }
};
