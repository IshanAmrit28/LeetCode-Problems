class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }
        bool c=false;
        bool v=false;
        bool n=false;
        
        int len=0;
        for(int i=0;i<word.length();i++){
            if(word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U'||
            word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                v=true;
                len++;
            }
            else if(word[i]>='0' && word[i]<='9'){
                n=true;
                len++;
            }
            else if(word[i]=='@' ||word[i]=='$' ||word[i]=='#'){
                return false;
            }
            else{
                c=true;
                len++;
            }
        }

        if(v && c && len>=3){
            return true;
        }else{
            return false;
        }
    }
};