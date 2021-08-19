// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    
    void combination(vector<vector<int>>& res, vector<int> curr, vector<int> pool, int pos, int k){
        vector<int> newCurr = curr;
        
        if(pos < pool.size() - (k-newCurr.size())+1)
            newCurr.push_back(pool[pos]);
        else
            return;
        
        if(newCurr.size() == k){
            res.push_back(newCurr);
            return;
        }
        
        
        for(int i = pos; i < pool.size(); i++)
            combination(res, newCurr, pool, i+1, k);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        res.push_back(curr);
        
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j < nums.size(); j++)
                combination(res, curr, nums, j, i);
        }
        
        return res;
    }
};
