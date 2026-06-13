class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        if(n!=t.length()){
            return false;
        }
        vector<int>mp(26,0);
        for(auto i:s){
            mp[i-'a']++;
        }
        for(auto i:t){
            mp[i-'a']--;
        }

        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                return false;
            }
        }
        return true;

    }
};