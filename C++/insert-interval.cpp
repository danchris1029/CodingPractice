// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> res_interval;
        int k;
        
        int lowInterval = newInterval[0],
            highInterval = newInterval[1];
            
        if(intervals.size() == 0){
            res.push_back(newInterval);
            return res;
        }
        
        for(auto interval:intervals){
            if(interval[0] <= newInterval[0] && interval[1] >= newInterval[0]){
                lowInterval = interval[0];
                break;
            }
            if(interval[0] > newInterval[0])
                 break;
        }
        for(auto interval:intervals){
            if(interval[0] <= newInterval[1] && interval[1] >= newInterval[1]){
                highInterval = interval[1];
                break;
            }
        }
        
        k = 0;
        while(k < intervals.size() && intervals[k][0] <= highInterval){
            if(!(intervals[k][0] >= lowInterval && intervals[k][1] <= highInterval))
                res.push_back(intervals[k]);
            k++;
        }
        
        res_interval = {lowInterval, highInterval};
        res.push_back(res_interval);
            
        for(int i = k; i < intervals.size(); i++)
            res.push_back(intervals[i]);
    
        return res;
    }
};
