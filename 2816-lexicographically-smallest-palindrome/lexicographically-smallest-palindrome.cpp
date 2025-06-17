class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        int low = 0, high = n-1;

        while(low < high){
            if(s[low] < s[high]) s[high] = s[low];
            else
               s[low] = s[high];

            low++; 
            high--;    
        }

        return s;
    }
};