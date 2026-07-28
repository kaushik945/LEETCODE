class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        int odd = -1;
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i]%2)
                odd = i;
        }
        if(n%2){
            s[n/2] = odd+'a';
            freq[odd]--;
        }
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < 26; j++){
                if(freq[j]>0){
                    s[i] = j + 'a';
                    s[n-i-1] = j + 'a';
                    freq[j] -= 2;
                    break;
                }
            }
        }
        return s;
    }
};