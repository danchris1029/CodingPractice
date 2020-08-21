/*
On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.

You can move according to the next rules:

In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int curX = points[0][0];
        int curY = points[0][1];
        int second = 0;
        
        for(int i = 0; i < points.size()-1; i++){
            while(true){
                if(curX < points[i+1][0])
                    curX++;
                else if(curX > points[i+1][0])
                    curX--;
                
                if(curY < points[i+1][1])
                    curY++;
                else if(curY > points[i+1][1])
                    curY--;
                
                //cout << "X pos: " << curX << endl;
                //cout << "Y pos: " << curY << endl;
                
                second++;
                
                if(curX == points[i+1][0] && curY == points[i+1][1])
			        break;
			        
            }
            //cout << "time: " << i << endl;
            //cout << "second: " << second << endl;
        }
        
        return second;
        
    }
};
