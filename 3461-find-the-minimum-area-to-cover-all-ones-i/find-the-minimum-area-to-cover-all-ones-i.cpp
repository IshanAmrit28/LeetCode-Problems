class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rmin=INT_MAX,rmax=INT_MIN,cmin=INT_MAX,cmax=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rmin=min(rmin,i);
                    rmax=max(rmax,i);
                    cmin=min(cmin,j);
                    cmax=max(cmax,j);
                }
            }
        }
        int area=((rmax-rmin)+1)*((cmax-cmin)+1);
        return area;
    }
};