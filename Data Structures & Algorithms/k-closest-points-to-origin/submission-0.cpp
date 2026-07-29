class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            int dis_square = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            // cout<<dis_square<<endl;
            pq.push({dis_square,{points[i][0],points[i][1]}});
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            // cout<<it.first<<endl;
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};