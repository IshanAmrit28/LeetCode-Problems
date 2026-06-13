class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // int n=nums.size();
        // unordered_map<int,int>mp;
        // for(auto x:nums){
        //     mp[x]++;
        // }
        // for(auto x:mp){
        //     if(x.second>1){
        //         return true;
        //     }
        // }
        // return false;
        unordered_set<int>st;
        for(auto &x:nums){
            if(st.count(x)>0){
                return true;
            }
            st.insert(x);
        }
        return false;
    }
};