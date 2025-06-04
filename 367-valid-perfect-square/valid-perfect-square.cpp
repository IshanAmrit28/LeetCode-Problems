class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0){
            return false;
        }else if(num==0 || num==1){
            return true;
        }else{
            int odd=1;
            long long sum=0;
            while (sum < num) {
                sum += odd;
                if (sum == num) {
                    return true;
                }
                odd += 2;
            }
            return false;
        }
    }
};