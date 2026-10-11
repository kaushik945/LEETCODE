class Solution {
public:
    void func(int start,int k,int n,vector<int> temp,vector<vector<int>> &ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
            temp.push_back(i);
            func(i+1,k,n,temp,ans);
            temp.pop_back();
            
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        func(1,k,n,{},ans);
        return ans;
    }
};