class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //make the hashmap

        unordered_map<int, int> count;
        int n = fruits.size();
        int left = 0;
        int max_count = 0;
        for(int right=0; right<n; right++){
            count[fruits[right]]++;

            if(count.size()>2){
                count[fruits[left]]--;
                if(count[fruits[left]]==0){
                    count.erase(fruits[left]);
                }
                left++;
            }
            max_count = max(max_count, right-left+1);
        }
        return max_count;

        
    }
};