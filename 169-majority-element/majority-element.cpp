class Solution {
public:
    int majorityElement(vector<int>& num) {
        unordered_map<int,int> freq;
        int n = num.size(); 
        for(int number: num){
            freq[number]++;
            
            if(freq[number]>n/2){
            return number;
        }
        }
        return 0;
        
        
    }
};