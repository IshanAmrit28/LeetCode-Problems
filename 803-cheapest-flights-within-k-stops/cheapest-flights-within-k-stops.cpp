class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n,INT_MAX));

        dp[0][src] = 0;

        for (int stops = 0; stops <= k + 1; ++stops) {
            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (dp[stops][from] != INT_MAX) {
                    if (stops + 1 <= k + 1) {
                        dp[stops + 1][to] = min(dp[stops + 1][to], dp[stops][from] + price);
                    }
                }
            }
        }

        int min_price = INT_MAX;
        for (int stops = 0; stops <= k + 1; ++stops) {
            min_price = min(min_price, dp[stops][dst]);
        }

        return (min_price == INT_MAX) ? -1 : min_price;
    }
    
};