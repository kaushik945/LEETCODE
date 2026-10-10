class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans;
        int curr = 0;
      
        for(char c: s){
            if(c == ' '){
                if(curr) ans = (curr);
                curr = 0;
            }else{
                curr++;
            }
        }
        if(curr) ans = (curr);
        return ans ;
    }
};