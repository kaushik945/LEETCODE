
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> mp = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        };

        unordered_map<int, int> cnt;
        vector<string> ans;
        int num = 0;

        for(int i = 0; i < s.size(); i++){
            num = ((num << 2) | mp[s[i]]) & ((1 << 20) - 1);

            if(i >= 9){
                cnt[num]++;

                if(cnt[num] == 2){
                    ans.push_back(s.substr(i - 9, 10));
                }
            }
        }

        return ans;
    }
};
