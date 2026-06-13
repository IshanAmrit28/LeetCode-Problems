class Solution {
public:
    void genkey(string&key, string &s){
        vector<int>temp(26,0);
        for(auto &i:s){
            temp[i-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(temp[i] != 0){
                key += (i + 'a');        
                key += to_string(temp[i]); 
            }
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return {strs};
        }
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string key="";
            genkey(key,strs[i]);
            mp[key].push_back(strs[i]);
        }
        for(auto &i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};