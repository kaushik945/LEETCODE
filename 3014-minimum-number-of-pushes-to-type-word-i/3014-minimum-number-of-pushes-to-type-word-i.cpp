class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for(int i = 1; i <= n/8;i++){
            ans += 8*(i);
        }
        ans += (n/8+1)*(n%8);
        return ans;
    }
};