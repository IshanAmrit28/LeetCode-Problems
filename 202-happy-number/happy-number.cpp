class Solution {
public:
    bool isHappy(int n) {
        set<int>check;
        while(true){
            int sum=0;
            while(n!=0){
                int a=n%10;
                sum+=a*a;
                n=n/10;
            }

            if(sum==1){
                return true;
            }
            n=sum;
            if(check.find(n)!=check.end()){
                return false;
            }else{
                check.insert(n);
            }
        }
    }
};