class Solution {
public:
    bool isPalindrome(int x) {
         if(x<0){
            return false;
        }
        else{
            long y=0;
            int z=x;
            while(x!=0){
               y=y*10+x%10;
               x=x/10; 
            }
            if(y!=z){
                return false;
            }
        }
    return true;
    }
    
};