class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string shuffledString = s;
        for(int i = 0; i < s.length(); i++)
            shuffledString[indices[i]] = s[i];
        
        return shuffledString;
    }
};
