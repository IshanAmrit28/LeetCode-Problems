class Solution {
public:
    void divisor(int n, unordered_set<int>&arr){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                    arr.insert(i);
                    arr.insert(n/i);
            }
        }

    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto x:nums){
            unordered_set<int>arr;
            divisor(x,arr);
            if(arr.size()==4){
                for(auto y:arr){
                    ans+=y;
                }
            }
        }
        return ans;
    }
};