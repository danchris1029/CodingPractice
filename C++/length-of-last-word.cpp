//Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSpace = 0;
        int k = s.size()-1;
        while(s[k] == ' '){
            k--;
        }
        int excessSpace = s.size()-k-1;
        
        for(int i = k; i >= 0; i--){
            if(s[i] == ' '){
                lastSpace = i+1;
                break;
            }
        }
        return s.size()-lastSpace-excessSpace;
    }
};
