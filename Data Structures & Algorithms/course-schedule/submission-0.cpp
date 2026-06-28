class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDeg(numCourses,0);
        vector<vector<int>>adjLs(numCourses);
        for(auto it: prerequisites){
            inDeg[it[0]]++;
            adjLs[it[1]].push_back(it[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adjLs[node]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
        }
        return ans.size() == numCourses;
    }
};