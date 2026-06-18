class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int diff;
        int maxprof = 0;
        while(j < prices.size()){
            diff = prices[j] - prices[i];
            maxprof = max(maxprof, diff);
            if(diff < 0)
                i = j;
            j++;
        }
        return maxprof;
    }
};
