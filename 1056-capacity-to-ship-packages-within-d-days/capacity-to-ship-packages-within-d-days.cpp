class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = high;

        auto canShip = [&](int cap){
            int ships = 1;
            int currCap = cap;
            for(int w : weights){
                if(currCap - w < 0){
                    ships += 1;
                    currCap = cap;
                }
                currCap -= w;
            }
            return ships <= days;
        };
        while(low <=high){
            int cap = low + (high-low)/2;

            if(canShip(cap)){
                res = min(res, cap);
                high = cap-1;

            }
            else{
                low = cap+1;
            }

    }
    return res;
    }
};