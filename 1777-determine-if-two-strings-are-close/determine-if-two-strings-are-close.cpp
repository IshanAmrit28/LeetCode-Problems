class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        vector<int>l1(26,0),l2(26,0);
        for(int i=0;i<s1.length();i++){
            l1[s1[i]-'a']++;
            l2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            bool c1=l1[i]>0;
            bool c2=l2[i]>0;
            if(c1!=c2){
                return false;
            }
        }

        unordered_map<int,int>mp;
        for(int i=0;i<26;i++){
            mp[l1[i]]++;
            mp[l2[i]]--;
        }
        for(auto i:mp){
            if(i.second!=0){
                return false;
            }
        }
        return true;
        
        
        
    }
};