class Solution {
public:
    bool doesAliceWin(string s) {
        bool flag=false;
        for( auto i:s){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U'){
                flag=true;
                break;
            }
        }
        return flag;
    }
};