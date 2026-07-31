class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(auto it : tasks){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        queue<pair<int,pair<char,int>>>q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().first == time){
                auto temp = q.front();
                q.pop();
                pq.push({temp.second.second,temp.second.first});
            }
            if(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                if(it.first>1){
                    q.push({time+n+1,{it.second,it.first-1}});
                }
            }
        }
        return time;
    }
};