class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int>mp(26,0);
        for(auto i:letters){
            mp[i-'a']=1;
        }
        for(int i=target-'a'+1;i<26;i++){
            if(mp[i]==1){
                return char(i+'a');
                break;
            }
        }
        return letters[0];
    }
};