// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

class Solution {
public:
    void combination(vector<vector<int>>& res, vector<int> curr, vector<int> pool, int pos, int k){
        vector<int> newCurr = curr;
        
        if(pos < pool.size()-(k-curr.size())+1)
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
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> list,
                    curr;
        
        for(int i = 1; i <= n; i++)
            list.push_back(i);
        
        for(int i = 0; i <= list.size()-k; i++)
            combination(res, curr, list, i, k);
        
        return res;
    }
};
