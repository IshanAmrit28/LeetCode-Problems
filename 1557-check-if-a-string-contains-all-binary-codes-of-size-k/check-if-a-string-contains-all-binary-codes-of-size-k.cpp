class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n=s.length();
        if(k>=n){
            return false;
        }
        for(int i=0;i<=n-k;i++){
            st.insert(s.substr(i,k));
        }
        long long num=pow(2,k);
        if(st.size()==num){
            return true;
        }else{
            return false;
        }
    }
};