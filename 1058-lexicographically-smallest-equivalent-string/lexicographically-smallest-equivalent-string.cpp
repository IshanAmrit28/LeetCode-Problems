class Solution {
public:

    int findParent(int x, vector<int>&parent){
        if(x!=parent[x]){
            parent[x]=findParent(parent[x],parent);
        }
        return parent[x];
    }

    void unionSet(int x,int y,vector<int>&parent){
        int px=findParent(x,parent);
        int py=findParent(y,parent);
        if(px==py){
            return;
        }
        if(px<py){
            parent[py]=px;
        }
        else{
            parent[px]=py;
        }        
    }


    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>parent(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<s1.length();i++){
            int a=s1[i]-'a';
            int b=s2[i]-'a';

            unionSet(a,b,parent);
        }
        string result;
        for(char x:baseStr){
            int rep=findParent(x-'a',parent);
            result+=(char)(rep+'a');
        }
        return result;
    }
};