class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi=INT_MIN;
        for(auto x:candies){
            if(x>maxi){
                maxi=x;
            }
        }
        for(auto x:candies){
            if(x+extraCandies>=maxi){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};