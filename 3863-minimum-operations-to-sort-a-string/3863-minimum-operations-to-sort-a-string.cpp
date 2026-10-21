class Solution {
public:
    int minOperations(string s) {
        int maxI = *ranges::max_element(s);
        int minI = *ranges::min_element(s);
        int n = s.size();
        bool isSorted = true;
        for(int i = 1; i < n; i++){
            if(s[i-1] > s[i]){
                isSorted = false;
            }
            
            
        }
        if(isSorted) return 0;
        if(n==2) return -1;
        if(maxI == s.back() || minI == s.front()){
            return 1;
        }
        for(int i = 1; i< n-1; i++){
            if(s[i] == maxI|| s[i] == minI){
                return 2;
            }
        }
        return 3;

    }
};