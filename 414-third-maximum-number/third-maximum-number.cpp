class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> bounded_set;

    for (int num : nums) {
        bounded_set.insert(num);

        
        if (bounded_set.size() > 3) {
            bounded_set.erase(bounded_set.begin()); 
        }
    }

    
    if (bounded_set.size() < 3) {
        
        return *bounded_set.rbegin(); 
    }

    
    return *bounded_set.begin();
        
    }
};