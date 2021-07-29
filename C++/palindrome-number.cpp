// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
        string numStr = to_string(x);
        int left, right;
        
        // odd
        if(numStr.size()%2){
            left = (numStr.size()/2)-1;
            right = (numStr.size()/2)+1;
        }
        // even
        else{
            left = (numStr.size()/2)-1;
            right = (numStr.size()/2);
        }
        
        while(left >= 0 && right < numStr.size()){
            if(numStr[left--] != numStr[right++])
                return false;
        }
        return true;
            
    }
};
