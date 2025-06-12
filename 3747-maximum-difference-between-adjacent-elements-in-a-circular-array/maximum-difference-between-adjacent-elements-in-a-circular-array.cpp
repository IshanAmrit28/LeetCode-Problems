class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(nums[0]>nums[n-1]){
            ans=nums[0]-nums[n-1];
        }else{
            ans=nums[n-1]-nums[0];
        }
        
        for(int i=1;i<n;i++){
            int diff=0;
            if(nums[i-1]>nums[i]){
                diff=nums[i-1]-nums[i];
            }else{
                diff=nums[i]-nums[i-1];
            }
            ans=max(ans,diff);
        }

        return ans;
    }
};