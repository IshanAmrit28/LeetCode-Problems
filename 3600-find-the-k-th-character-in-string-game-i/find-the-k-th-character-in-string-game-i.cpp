class Solution {
public:

    void conversion(string &s,int k){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='z'){
                s+='a';
            }else{
                s+=s[i]+1;
            }

            if(s.length()==k){
                return;
            }
        }
        if(s.length()<k){
            conversion(s,k);
        }
    }
    char kthCharacter(int k) {
        string s="ab";
        if(k==1){
            return 'a';
        }
        conversion(s,k);
        return s[k-1];
    }
};