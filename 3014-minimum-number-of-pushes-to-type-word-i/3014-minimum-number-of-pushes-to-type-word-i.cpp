class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
       ans+= 8*((n/8)*(n/8+1))/2;
        ans += (n/8+1)*(n%8);
        return ans;
    }
};