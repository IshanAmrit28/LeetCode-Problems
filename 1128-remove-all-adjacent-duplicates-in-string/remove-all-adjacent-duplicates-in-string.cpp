class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        
        string ans="";
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop(); 
            } else {
                st.push(c);
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};