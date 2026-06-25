class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>temp;
        for(int i=0;i<n;i++){
            double time = (double)(target - position[i])/speed[i];
            temp.push_back({position[i],time});
        }
        sort(temp.begin(),temp.end());
        int ans = 0;
        double maxTime = 0.0;
        for(int i=n-1;i>=0;i--){
            if(maxTime < temp[i].second){
                maxTime = temp[i].second;
                ans++;
            }
        }
        return ans;
    }
};
