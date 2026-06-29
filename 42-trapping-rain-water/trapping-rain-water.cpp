class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;

        int leftmax=height[0];
        int rightmax=height[right];
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){
                leftmax=max(leftmax,height[left]);
                if(leftmax-height[left]>0){
                    ans+=leftmax-height[left];
                }
                left++;
            }else{
                rightmax=max(rightmax,height[right]);
                if(rightmax-height[right]>0){
                    ans+=rightmax-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};