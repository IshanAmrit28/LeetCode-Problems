class Solution {
public:

// //recursion
// int solve(vector<int>&cost,int n){

//     // base case
//     if(n==0){
//         return cost[0];
//     }
//     if(n==1){
//         return cost[1];
//     }

//     int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
//     return ans;

// }
// //top down
// int solve2(vector<int>&cost,int n,vector<int> &dp){

//     // base case
//     if(n==0){
//         return cost[0];
//     }
//     if(n==1){
//         return cost[1];
//     }
//     //step 3
//     if(dp[n]!=-1){
//         return dp[n];
//     }

//     //step 2
//     dp[n]=cost[n]+min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
//     return dp[n];

// }

//bottom up
int solve3(vector<int>&cost,int n){
    // step 1
    int prev1=cost[1];
    int prev2=cost[0];
    // base case
    //step 2
    
       
    
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
        

    }

    return min(prev1,prev2);

}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //recursion
        //can be simplified
        // int ans=min(solve(cost,n-1),solve(cost,n-2));
        // return ans;
    // top down
        //step 2
        // vector<int>dp(n+1,-1);
        // int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));

    //bottom up
        int ans=solve3(cost,n);
        return ans;
    }
};