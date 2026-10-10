class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int maxi = intervals[0][1];
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i = 1; i < intervals.size(); i++ ){
            if(maxi >= intervals[i][0]){
                maxi = max(maxi,intervals[i][1]);
                ans.back()[1] = maxi;
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
                maxi = intervals[i][1];
            }
            
        }
        
        return ans;
    }
};