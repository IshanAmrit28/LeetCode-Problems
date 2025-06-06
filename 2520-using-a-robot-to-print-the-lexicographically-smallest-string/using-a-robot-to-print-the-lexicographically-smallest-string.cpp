class Solution {
public:
    string robotWithString(string s) {
        map<char, int> freq;
        for (char c : s) freq[c]++;

        stack<char> t;
        string result;
        char smallest = freq.begin()->first;

        for (char c : s) {
            t.push(c);
            freq[c]--;

            if (freq[c] == 0) freq.erase(c);

            if (!freq.empty())
                smallest = freq.begin()->first;

            while (!t.empty() && (freq.empty() || t.top() <= smallest)) {
                result += t.top();
                t.pop();
            }
        }

        return result;
    }
};