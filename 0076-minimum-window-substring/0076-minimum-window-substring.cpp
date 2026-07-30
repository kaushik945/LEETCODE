class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        vector<int> freq(256,0);
        for(int i = 0; i < m;i++){
            freq[t[i]]++;
        }
        int start = -1; int mini = INT_MAX;
        int cnt = 0;
        int i=0,j=0;
        while(j < n){
            if(freq[s[j]] > 0) cnt++;
            freq[s[j]]--;
            while(cnt == m){
                if(j-i+1 < mini){
                    mini = j-i+1;
                    start = i;
                }
                freq[s[i]]++;
                if(freq[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }
        return (start == -1) ? "":s.substr(start,mini);
        
    }
};