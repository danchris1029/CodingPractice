// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int minLen = 201;
        for(auto str: strs){
            if(str.size() < minLen)
                minLen = str.size();
        }
        
        int i = 0;
        while(i < minLen){
            for(auto str: strs){
                if(str[i] != strs[0][i])
                    return prefix;
            }
            prefix += strs[0][i++];
        }
        return prefix;
    }
};
