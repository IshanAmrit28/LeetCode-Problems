class Solution {
public:
    string reverseWords(string s) {
        vector<string>arr;
        string t="";
        for(char x : s){
            if(x == ' '){
                if(!t.empty()){
                arr.push_back(t);
                t = "";
            }
            } else {
                t += x;
            }
        }
        if(!t.empty()){
            arr.push_back(t);
        }
        
        reverse(arr.begin(),arr.end());
        string ans="";
        for(int i=0;i<arr.size()-1;i++){
            ans+=arr[i];
            ans+=" ";
        }
        ans+=arr[arr.size()-1];
        return ans;
    }
};