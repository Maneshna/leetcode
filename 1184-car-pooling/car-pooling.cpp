class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int change[1001] = {};

        for (auto trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            change[from] += passengers;
            change[to] -= passengers;
        }

        int passengers = 0;

        for (int i = 0; i <= 1000; i++) {
            passengers += change[i];

            if (passengers > capacity)
                return false;
        }

        return true;
        
        
    }
};