class Solution {
public:
    const int M=1e9+7;
    int numSub(string s) {
        int result=0;
        int count=0;
        for(char ch:s){
            if(ch=='1'){
                count++;
                result=(result+count)%M;
            }else{
                
                count=0;
            }
        }
        
        return result;
    }
};