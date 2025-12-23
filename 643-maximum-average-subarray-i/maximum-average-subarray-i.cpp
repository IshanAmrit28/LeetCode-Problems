class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        
        int currSum = 0;
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        
        int maxSum = currSum;
        
        for (int i = k; i < n; i++) {
            currSum = currSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }
        
        return (double)maxSum / k;
    }
};