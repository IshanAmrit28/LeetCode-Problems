class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector<int>toRemove(n,0);
        vector<vector<int>> mp(26);  
        set<char> availableChars;    

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (!availableChars.empty()) {
                char smallest = *availableChars.begin();  
                int idx = mp[smallest - 'a'].back();
                mp[smallest - 'a'].pop_back();
                toRemove[idx] = 1;

                
                if (mp[smallest - 'a'].empty()) {
                    availableChars.erase(smallest);
                }
            }
        } else {
            mp[s[i] - 'a'].push_back(i);
            availableChars.insert(s[i]);  
        }
    }

        string ans="";
        for(int i=0;i<n;i++){
            if(!toRemove[i]&&s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};