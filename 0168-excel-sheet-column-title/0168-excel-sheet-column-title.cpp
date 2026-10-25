class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            columnNumber--;
            int rem = columnNumber%26;
            ans += 'A' + rem;
            columnNumber /= 26; 
        }
        ranges::reverse(ans);
        return ans;
    }
};