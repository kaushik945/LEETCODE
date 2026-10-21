class Solution {
    unordered_set<string> st;
    int dp[301];
public:
    bool solve(int idx,string &s)
    {
        if(idx >= s.size()){
            return dp[idx] = true;
        }
        if(dp[idx] != -1) return dp[idx];
        if(st.find(s) != st.end()){
            return dp[idx] = true;
        }
        for(int l = 1; l <= s.size(); l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solve(idx+l,s)){
                return dp[idx] =  true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string c: wordDict){
            st.insert(c);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
        
    }
};