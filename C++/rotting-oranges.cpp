class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int orangeCount = 0;
        int rottenCount = 0;
        // we need to count every 2
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size();col++){
                if(grid[row][col] == 1)
                    orangeCount++;
            }
        }
        if(orangeCount == 0)
            return 0;
        
        int time = 0;
        int impossible = false;
        int allRotton = false;
        int i = 0;
        while(!impossible){
        impossible = true;
        for(int row = 0; row < grid.size(); row++){
            
                for(int col = 0; col < grid[row].size();col++){
                    int colVal = grid[row][col];
                    
                    // Mark rotton oranges as three as that we don't read them in this run
                    if(colVal == 2){
                            
                        if(col != 0){
                            if(grid[row][col-1] == 1){
                                impossible = false;
                                rottenCount++;
                                grid[row][col-1] = 3;
                            }
                        }
                        if(col != grid[row].size()-1){
                            if(grid[row][col+1] == 1){
                                impossible = false;
                                rottenCount++;
                                grid[row][col+1] = 3;
                            }
                        }
                            
                        if(row != 0){
                            if(grid[row-1][col] == 1){
                                impossible = false;
                                rottenCount++;
                                grid[row-1][col] = 3;
                            }
                        }
                            
                        if(row != grid.size()-1){
                            if(grid[row+1][col] == 1){
                                impossible = false;
                                grid[row+1][col] = 3;
                                rottenCount++;
                            }
                        }
                        
                        //rottenCount++;
                        if(rottenCount == orangeCount){
                            time++;
                            return time;
                        }
                    }
                    //printf("%d ", grid[row][col]);
                }
                //cout << endl;
            }
            
            if(impossible)
                return -1;
            time++;
//             // Convert marked oranges to rotton
            for(int row = 0; row < grid.size(); row++){
                for(int col = 0; col < grid[row].size();col++){
                    if(grid[row][col] == 3)
                        grid[row][col] = 2;
                    printf("%d ", grid[row][col]);
                }
                cout << endl;
            }
            cout << endl;
            i++;
        }
            
        
//         while(!allRotton){
//             impossible = true;
            
//             for(int row = 0; row < grid.size(); row++){
//                 int row = grid[row];
//                 for(int col = 0; col < row.size();col++){
//                     colVal = row[col];
                    
//                     // Mark rotton oranges as three as that we don't read them in this run
//                     if(colVal == 2){
//                         if(impossible)
//                             impossible = false;
//                         if(col != 0)
//                             row[col-1] = 3;
//                         if(col != row.size()-1)
//                             row[col+1] = 3;
//                         if(row != 0)
//                             grid[row-1][col] = 3;
//                         if(row != row.size()-1)
//                             grid[row+1][col] = 3;
                        
//                         if(rottonCount == counted){
//                             time++;
//                             return time;
//                         }
//                     }
//                 }
//             }
            
//             if(impossible)
//                 return -1;
            
//             time++;
            

        return 100;
    }
};