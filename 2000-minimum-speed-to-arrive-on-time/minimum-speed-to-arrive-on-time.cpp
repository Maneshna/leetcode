class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<- n-1) return -1;

        int low =1;
        int high = 1e7;
        int ans = -1;

        while(low <=high){
            int mid = low + (high-low)/2;
            double time =0;

            for(int i=0;i<n-1; i++){
                time += (dist[i]+mid-1)/mid;
            }
            time += (double)dist[n-1] /mid;

            if(time <= hour){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};