class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int i=0,j=0;
        bool flag=false;
        string ans="";
        while(i<n && j<m){
            if(flag){
                ans+=word2[j];
                j++;
                flag=!flag;
            }else{
                ans+=word1[i];
                i++;
                flag=!flag;
            }
        }
        if(i<n){
            for(i;i<n;i++){
                ans+=word1[i];
            }
        }
        if(j<m){
            for(j;j<m;j++){
                ans+=word2[j];
            }
        }
        return ans;
    }
};