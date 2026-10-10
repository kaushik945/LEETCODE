class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<int> ans;
        int curr = 0;
      
        for(char c: s){
            if(c == ' '){
                if(curr) ans.push_back(curr);
                curr = 0;
            }else{
                curr++;
            }
        }
        if(curr) ans.push_back(curr);
        return ans.back();
    }
};