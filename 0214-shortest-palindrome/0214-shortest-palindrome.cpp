class Solution {
public:
    void LPS(vector<int> &lps, string s){
        int n = s.size();
        int len = 0;
        lps[0] = 0;
        int j = 1;

        while(j < n){
            if(s[j] == s[len]){
                len++;
                lps[j] = len;
                j++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[j] = 0;
                    j++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        if(s.empty()) return s;

        int n = s.size();
        string rev = s;
        ranges::reverse(rev);

        string temp = s + '-' + rev;
        vector<int> lps(temp.size());
        LPS(lps,temp);
        int lpsAns = lps[temp.size()-1];
        string ans = rev.substr(0,n-lpsAns);

        return ans + s;
    }
};