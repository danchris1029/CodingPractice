// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

class Solution {
public:
    void recursComb(int start, int r, string pool, string curr,
                    vector<string>& res){
        if(curr.size() == r){
            res.push_back(curr);
            return;
        }
        
        int maxChars;
        if(pool[start] == 'w' || pool[start] == 'p')
            maxChars = 4;
        else
            maxChars = 3;
        for(int k = 0; k < maxChars; k++){
            string newCurr = curr;
            newCurr += pool[k+start];
            recursComb(start+maxChars, r, pool, newCurr, res);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> letMap = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                 "pqrs", "tuv", "wxyz"}; 
        vector<string> res;
        string pool = "";
        
        if(digits == "")
            return res;
        
        for(char c: digits){
            int num = c-'0';
            pool += letMap[num];
        }
        
        recursComb(0, digits.size(), pool, "", res);
        
        return res;
    }
};
