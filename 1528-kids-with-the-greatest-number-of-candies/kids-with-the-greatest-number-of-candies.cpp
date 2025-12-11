class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int mx=candies[0];
        for(int i = 0;i<n;i++){
            if(candies[i]>mx){
                mx= candies[i];
            }
        }
        vector<bool> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = (candies[i] + extraCandies >= mx);
        }

        return result;
        }
    
};