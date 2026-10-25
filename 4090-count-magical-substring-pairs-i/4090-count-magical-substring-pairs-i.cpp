class Solution {
public:
    int countMagicalPairs(string s) {

        int n = s.size();
        long long count = 0;

        for(int j = 0; j < n; j++){

            vector<int> freq(27,0) , cnt(27,0);
            int distinct = 0;

            // i to j
            for(int i = j; i >= 0; i--){

                if(freq[s[i]-'a'] == 0) distinct++;
                freq[s[i]-'a'] = 1;
                cnt[distinct]++;

            }

            fill(freq.begin(), freq.end(), 0);
            distinct = 0;

            // j+1 to k
            for(int k = j+1; k < n; k++){

                if(freq[s[k]-'a'] == 0) distinct++;
                freq[s[k]-'a'] = 1;
                count += cnt[distinct];

            }
        }

        return count;
        
    }
};