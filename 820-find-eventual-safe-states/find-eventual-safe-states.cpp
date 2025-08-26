class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<vector<int>>&graph){
        vis[node]=2;
        for(auto i:graph[node]){
            if(vis[i]==0){
                if(dfs(i,vis,graph)){
                    return true;
                }
            }else if(vis[i]==2){
                return true;
            }
        }
        vis[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans,vis(n,0);
        for(int i=0;i<n;i++){
            if(!dfs(i,vis,graph)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};