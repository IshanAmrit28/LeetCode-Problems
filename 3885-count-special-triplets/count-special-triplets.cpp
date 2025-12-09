class Solution {
public:
    int specialTriplets(vector<int>& nums) {
    const int MOD = 1e9 + 7;
    int n = nums.size();
    unordered_map<int, int> leftFreq, rightFreq;

    
    for (int num : nums) {
        rightFreq[num]++;
    }

    long long total = 0;

    for (int j = 0; j < n; ++j) {
        int mid = nums[j];
        rightFreq[mid]--; 

        int target = mid * 2;
        long long countLeft = leftFreq[target];  
        long long countRight = rightFreq[target]; 

        total = (total + countLeft * countRight) % MOD;

        leftFreq[mid]++; 
    }

    return total;
    }
};