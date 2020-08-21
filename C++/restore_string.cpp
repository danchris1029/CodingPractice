/*
Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string shuffledString = s;
        for(int i = 0; i < s.length(); i++)
            shuffledString[indices[i]] = s[i];
        
        return shuffledString;
    }
};
