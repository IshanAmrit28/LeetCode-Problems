class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus=[](int cnta,int cntb)->int{
            return((cnta%2)<<1)|(cntb%2);
        };

        int n=s.size();
        int ans=INT_MIN;
        for(char a='0';a<='4';a++){
            for(char b='0';b<='4';b++){
                if(a==b){
                    continue;
                }
                int best[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
                int cnta=0,cntb=0;
                int preva=0,prevb=0;
                int left=-1;
                for(int right=0;right<n;right++){
                    cnta+=(s[right]==a);
                    cntb+=(s[right]==b);
                    while (right - left >= k && cntb - prevb >= 2) {
                        int leftStat = getStatus(preva, prevb);
                        best[leftStat] = min(best[leftStat], preva - prevb);
                        left++;
                        preva += (s[left] == a);
                        prevb += (s[left] == b);
                    }
                    int rightTarget=getStatus(cnta,cntb);
                    int target=rightTarget^0b10;
                    if(best[target]!=INT_MAX){
                        ans=max(ans,(cnta-cntb)-best[target]);
                    }
                }
            }
        }
        return (ans==INT_MIN?-1:ans);
    }
};