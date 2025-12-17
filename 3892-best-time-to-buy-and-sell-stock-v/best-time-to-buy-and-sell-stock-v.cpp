class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        if(n==0||k==0) return 0;

        vector<vector<long long>>dp(k+1,vector<long long>(n,0));
        for( int t=1;t<=k;t++){
            long long maxBuy=-prices[0];
            long long maxSell=prices[0];

            for(int d=1;d<n;d++){
                dp[t][d]=max(dp[t][d-1], max((long long) prices[d]+ maxBuy,maxSell-(long long)prices[d]));
                maxBuy=max(maxBuy,dp[t-1][d-1]-prices[d]);
                maxSell=max(maxSell,dp[t-1][d-1]+prices[d]);
                
            }
        }
        return dp[k][n-1];
    }
};