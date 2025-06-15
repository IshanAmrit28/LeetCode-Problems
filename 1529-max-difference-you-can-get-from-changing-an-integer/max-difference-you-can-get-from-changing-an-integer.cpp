class Solution {
public:
int maxDiff(int num) {
    string s = to_string(num);
    
    
    string high = s;
    for (char c : s) {
        if (c != '9') {
            for (char &ch : high) {
                if (ch == c) ch = '9';
            }
            break;
        }
    }
    
    
    string low = s;
    if (s[0] != '1') {
        char x = s[0];
        for (char &ch : low) {
            if (ch == x) ch = '1';
        }
    } else {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                char x = s[i];
                for (char &ch : low) {
                    if (ch == x) ch = '0';
                }
                break;
            }
        }
    }

    int a = stoi(high);
    int b = stoi(low);
    return a - b;
    }
};
