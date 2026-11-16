class Solution {
public:
    string digitSum(string s, int k) {
        int sum = 0;
        while(s.size() > k){
            string temp = "";
            for(int i = 0; i < s.size(); i += k){
                int t = 0;
                for(int j = 0; j < k; j++){
                    if(i+j < s.size()) t += s[i+j] -'0';
                }
                temp += to_string(t);
            }
            s = temp;
        }
        return s;
    }
};