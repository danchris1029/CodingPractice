// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> list;
        for(int y = 0; y < matrix.size(); y++){
            for(int x = 0; x < matrix[0].size(); x++){
                list.push_back(matrix[y][x]);
            }
        }
        
        
        if(list.size() == 1){
            if(list[0] == target)
                return true;
            else
                return false;
        }
        
        int h = list.size()-1;
        int l = 0;
        int m;
        
        while(l < h){
            m = l+(h-l)/2;
            
            if(list[h] == target)
                return true;
            if(list[l] == target)
                return true;
            
            if (list[m] > target)
                h = m-1;
            else if (list[m] < target)
                l = m+1;
            else
                return true;
        }
        
        return false;
    }
};
