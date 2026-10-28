class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0], ans = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            ans = max(ans, prices[i]-low);
            low = min(low, prices[i]);
        }
        return ans;
    }
};
