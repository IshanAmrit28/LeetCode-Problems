class Solution {
public:
    int maxSum(vector<int>& num) {
        int n=num.size();
        sort(num.begin(),num.end());
        unordered_map<int,int>mp;
        int sum=0;
        if(num[n-1]<0){
            return num[n-1];
        }else{
            for(int i=n-1;i>=0;i--){
                if(mp.find(num[i])==mp.end()&& num[i]>0){
                    mp[num[i]]=sum+num[i];
                    sum+=num[i];
                }
            }
        }
        return sum;
    }
};