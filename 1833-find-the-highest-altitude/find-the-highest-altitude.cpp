class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int n=gain.size();
        // vector<int>arr(n+1);
        int prev=0;
        for(int i=0;i<n;i++){
            prev+=gain[i];
            ans=max(ans,prev);
        }
        // for(auto i:arr){
        //     ans=max(i,ans);
        // }
        return ans;
    }
};