class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN;
        int n=gain.size();
        vector<int>arr(n+1);
        arr[0]=0;
        for(int i=0;i<n;i++){
            arr[i+1]=arr[i]+gain[i];
        }
        for(auto i:arr){
            ans=max(i,ans);
        }
        return ans;
    }
};