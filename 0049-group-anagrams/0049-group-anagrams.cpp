class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> sorted;
        for(auto s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            sorted.push_back({temp,s});
        }
        sort(sorted.begin(),sorted.end());

        vector<vector<string>> ans; vector<string> temp;
        temp.push_back(sorted[0].second);
        for(int i = 1; i < sorted.size(); i++){
            if(sorted[i].first != sorted[i-1].first){
                ans.push_back(temp);
                temp.clear();
                temp.push_back(sorted[i].second);
            }else{
                temp.push_back(sorted[i].second);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};