class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];
    }
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp);
        int n = p.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX;
            for(int j = i+1; j<n; j++){
                if (p[j][1]>=p[i][1] && y>p[j][1]){
                    ans++;
                    y=p[j][1];
                }
            }
        }
        return ans;
    }
};