class Solution {
public:
    bool search(int x,vector<int>arr){
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (arr[mid] == x)
                return true;

             if (arr[mid] < x)
                low = mid + 1;

            else
                high = mid - 1;
        }

    
        return false;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_set<int>st1,st2;
        for(auto i:nums1){
            st1.insert(i);
        }
        for(auto i:nums2){
            st2.insert(i);
        }
        vector<vector<int>>ans(2);
        vector<int>v1;
        vector<int>v2;
        for(auto i:st1){
            if(!search(i,nums2)){
                v1.push_back(i);
            }
        }
        for(auto i:st2){
            if(!search(i,nums1)){
                v2.push_back(i);
            }
        }
        ans[0]=v1;
        ans[1]=v2;
        return ans;
    }
};