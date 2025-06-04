class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        long long prev=1;
        for(int i=1;i<rowIndex+1;i++){
            long long value=(prev*(rowIndex+1-i))/i;
            ans.push_back(value);
            prev=value;
        }
        return ans;
    }
};