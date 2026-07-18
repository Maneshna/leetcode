class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> window;
        int left =0;
        int maxlength = 0;

        for(int right = 0; right<s.size(); right++){
            //now if the letter is already there and mapped in the hashmap we move left++ and also drop the mapping of that letter from the hashmap

            while(window.count(s[right])){
                window.erase(s[left]);
                left++; //this means that the next element coming is the one that already exsisted so we need to remove the left most from the hashmap and also shift the window
            }
            window.insert(s[right]);
            //regardless whether the letter was mapped before and remove or it was unique, we need t map it now so that is why it is not written as an if else statement.

            //now we find the max element
            maxlength = max(maxlength, right-left+1);
        }
        return maxlength;


        
    }
};