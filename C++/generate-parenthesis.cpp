class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // check a list of elements where 1 = '(' and 2 = ')' to see how many
        // valid parentheses formed so far.
        // ())(
        // l = 1, 
        // if(r > l) then invalid string
        
        // each list of elements will have n*2 positions with n left and n right parenthesis
        
        vector<string> validForms;
        string currList;
        
        parenthRecurs(n, currList, validForms, 0, 0);
        
        return validForms;
    }
    
    void parenthRecurs(int n, string currList, vector<string> &validForms, int l, int r){
        
        if(r == n){
            validForms.push_back(currList);
            return;
        }
        
        string addLeft = currList;
        string addRight = currList;
        
        if(l < n){
            addLeft += "(";
            parenthRecurs(n, addLeft, validForms, l+1, r);
        }
        if(r+1 <= l){
            addRight += ")";
            parenthRecurs(n, addRight, validForms, l, r+1);
        }
    }
};
