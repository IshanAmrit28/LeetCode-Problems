class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        stack<char> t;
        string result;
        
        // Frequency count of all characters
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        char smallest = 'a';

        for (char c : s) {
            t.push(c);
            freq[c - 'a']--;

            // Update smallest remaining char
            while (smallest <= 'z' && freq[smallest - 'a'] == 0) {
                smallest++;
            }

            // Pop from stack if it's <= smallest char left in s
            while (!t.empty() && t.top() <= smallest) {
                result += t.top();
                t.pop();
            }
        }

        return result;
    }
};