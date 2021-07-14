class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        
        int x = 0;
        int y = 0;
        int rightBoundary = n-1;
        int leftBoundary = 0;
        int topBoundary = 0;
        int bottomBoundary = n-1;
        
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        int i = 1;
        
        
        int testValue = n*n+1;
        while(i < testValue){
            for(x = leftBoundary; x <= rightBoundary; x++){
                spiral[y][x] = i;
                i++;
            }
            x--;
            
            topBoundary++;
        
            for(y = topBoundary; y <= bottomBoundary; y++){
                spiral[y][x] = i;
                i++;
            }
            y--;
            
            rightBoundary--;
        
            for(x = rightBoundary; x >= leftBoundary; x--){
                spiral[y][x] = i;
                i++;
            }
            x++;
            
            bottomBoundary--;
            
            for(y = bottomBoundary; y >= topBoundary; y--){
                spiral[y][x] = i;
                i++;
            }
            y++;
 
            leftBoundary++;
        }
        
        return spiral;
    }
};