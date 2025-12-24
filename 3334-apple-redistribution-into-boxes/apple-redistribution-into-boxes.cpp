class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int applesum=0;
        int n=apple.size();
        int m=capacity.size();
        for(auto &x:apple){
            applesum+=x;
        }
        int ans=0;
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int cap=0;
        for(auto &x:capacity){
            if(cap>=applesum){
                break;
            }
            cap+=x;
            ans++;
        }
        return ans;
    }
};