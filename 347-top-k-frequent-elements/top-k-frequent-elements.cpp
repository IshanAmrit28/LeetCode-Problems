class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            int val=i.first;
            int freq=i.second;
            pq.push({freq,val});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};