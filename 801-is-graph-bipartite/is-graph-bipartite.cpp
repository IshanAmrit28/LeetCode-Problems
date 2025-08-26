class Solution {
public:
    bool bfs(int start,vector<vector<int>>&graph,vector<int>&col){
        queue<int>q;
        q.push(start);
        col[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:graph[node]){
                if(col[i]==-1){
                    col[i]=!col[node];
                    q.push(i);
                }
                else if(col[i]==col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!bfs(i,graph,col)) return false;
            }
        }
        return true;
    }
};