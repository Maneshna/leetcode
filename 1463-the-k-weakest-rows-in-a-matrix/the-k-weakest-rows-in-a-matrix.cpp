#include <algorithm>
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxHeap;

        for(int i =0; i<mat.size(); ++i){
            int s = upper_bound(mat[i].begin(), mat[i].end(), 1, greater<int>())-mat[i].begin();

            maxHeap.push({s, i});

            if(maxHeap.size()>k){
                maxHeap.pop();
            }

        }
        vector<int> result(k);
        for(int i = k-1; i>=0; --i){
            result[i] =maxHeap.top().second;
            maxHeap.pop();
        }
        return result;
    }
};