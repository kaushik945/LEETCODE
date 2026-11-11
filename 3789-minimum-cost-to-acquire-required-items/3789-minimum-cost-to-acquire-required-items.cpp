class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2 < costBoth){
            return 1LL*cost1*need1+1LL*cost2*need2;
        }
        int mini = min(need1,need2);
        return 1LL*mini*costBoth+ 1LL*(need1-mini)*min(cost1,costBoth) + 1LL*(need2-mini)*min(cost2,costBoth);
    }
};