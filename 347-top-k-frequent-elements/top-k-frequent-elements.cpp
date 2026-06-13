class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto &i:mp){
            int freq=i.second;
            int val=i.first;
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