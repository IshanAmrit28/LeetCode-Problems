class Solution {
public:
    int maxi(vector<int>&number,int  key){
        int maxi_num=0;
        for(int i=0;i<number.size();i++){
            if(number[i]==key){
                maxi_num=(maxi_num*10)+9;
            }else{
                maxi_num=(maxi_num*10)+number[i];
            }
        }
        return maxi_num;
    }
    int mini(vector<int>&number,int key){
        int mini_num=0;
        for(int i=0;i<number.size();i++){
            if(number[i]==key){
                mini_num=(mini_num*10)+0;
            }else{
                mini_num=(mini_num*10)+number[i];
            }
        }
        return mini_num;
    }

    int minMaxDifference(int num) {
        vector<int>number;
        while(num>0){
            int a=num%10;
            number.push_back(a);
            num=num/10;
        }
        reverse(number.begin(),number.end());
        int mini_1=INT_MIN;
        int maxi_1=INT_MAX;
        for(int i=0;i<number.size();i++){
            if(maxi_1==INT_MAX){
                if(number[i]<9){
                    maxi_1=number[i];
                }
            }
            if(mini_1==INT_MIN){
                if(number[i]>0){
                    mini_1=number[i];
                }
            }
        }
        int a=maxi(number,maxi_1);
        int b=mini(number,mini_1);
        return a-b;
    }
};