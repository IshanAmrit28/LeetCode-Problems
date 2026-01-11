class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(auto i:nums){
            total+=i;
        }
        
        int prev=0;
        for(int i=0;i<nums.size();i++){
            if(prev==(total-prev-nums[i])){
                return i;
            }
            prev+=nums[i];
        }
        return -1;
    }
};