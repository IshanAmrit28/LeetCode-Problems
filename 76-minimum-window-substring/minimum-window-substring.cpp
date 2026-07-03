class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int formed = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if (window[s[right]] <= need[s[right]])
                formed++;

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if (window[s[left]] < need[s[left]])
                    formed--;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};