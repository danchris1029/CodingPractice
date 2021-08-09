// Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int xSize = matrix[0].size(),
            ySize = matrix.size(),
            xPos = 0,
            yPos = 0;
        
        vector<int> nums;

        for(int i = 0; i < max(xSize, ySize)/2+1; i++){
            yPos = i;
            xPos = i;
            
            if(i == max(xSize, ySize)/2 && max(xSize, ySize)%2){
                nums.push_back(matrix[yPos][xPos]);
                break;
            }
            
            while(xSize != 1 && xPos < xSize-i-1){
                nums.push_back(matrix[yPos][xPos]);
                xPos++;
            }
            
            while(ySize != 1 && yPos < ySize-i-1){
                nums.push_back(matrix[yPos][xPos]);
                yPos++;
            }
            if(xPos == i || yPos == i){
                nums.push_back(matrix[yPos][xPos]);
                break;
            }
                
            while(xPos > 0+i){
                nums.push_back(matrix[yPos][xPos]);
                xPos--;
            }

            while(yPos > 0+i){
                nums.push_back(matrix[yPos][xPos]);
                yPos--;
            }
            if(ySize-(i*2) == 2 || xSize-(i*2) == 2)
                break;
        }
        
        return nums;
    
    }
};
