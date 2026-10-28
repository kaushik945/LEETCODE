class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        if(n==5) return 1;
        int cnt = 0;
        while(n>=5){
            n /= 5;
            cnt+=n;
        }
        return cnt;

    }
};