class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int element;
        for(int i=0;i<n;i++){
            if(count==0){
                element=nums[i];
                count=1;
            }else if(nums[i]==element){
                count++;
            }else{
                count--;
            }
        }

        // count=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==element){
        //         count++;
        //     }
        // }
        // if(count>n/2){
            return element;
        // }else{
        //     return-1;
        // }
    }
};