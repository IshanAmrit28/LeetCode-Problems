class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        n=n;
        unordered_set<int>seen;
        for(auto i:nums){
            if(seen.count(i)){
                return i;
            }
            seen.insert(i);
        }
        return -1;
    }
};