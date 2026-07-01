class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1){
            return 1;
        }
        if(s==""){
            return 0;
        }
        int ans=0;
        int l=0,r=0;
        set<char>st;
        while(r<s.length()){
            char ch=s[r];
            while(st.count(ch)){
                st.erase(char(s[l]));
                l++;
            }
            st.insert(ch);
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};