class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s=1,e=1;
        for(int i=0;i<n;i++){
            e=max(e,piles[i]);
        }
        int ans;
        while(s<=e){
            int mid = s+(e-s)/2;
            long long cnt = 0;
            for(int i=0;i<n;i++){
                cnt += (ceil)((piles[i]+mid-1)/mid);
            }
            if(cnt<=h){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
