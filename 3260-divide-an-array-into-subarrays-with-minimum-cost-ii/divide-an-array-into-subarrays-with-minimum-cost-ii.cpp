class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long base = nums[0]; // always included

        multiset<int> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        auto add = [&](int x) {
            if ((int)small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else {
                auto it = prev(small.end());
                if (x < *it) {
                    large.insert(*it);
                    sumSmall -= *it;
                    small.erase(it);
                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    small.insert(*jt);
                    sumSmall += *jt;
                    large.erase(jt);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        int l = 1;
        for (int r = 1; r < n; r++) {
            add(nums[r]);

            if (r - l + 1 > dist + 1) {
                remove(nums[l]);
                l++;
            }

            if ((int)small.size() == k - 1) {
                ans = min(ans, base + sumSmall);
            }
        }

        return ans;
    }
};