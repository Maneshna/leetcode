class Solution {
public:
    string removeKdigits(string num, int k) {
        string res=""; //monotonic stack;

        for(char c: num){
            while(!res.empty() && res.back() > c && k>0){ //if the current digit is smaller than the top of stack, remove the top number and enter the current in the 
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        //if k>0, remove the remaing digits from the end for example 12345, we really will never get a number smaller than the stack top so no number will ever get poped out and deleted. now what to do? we remove the number from the right side which obviously means we will be removing the k largest digits and getting the smallest possible number.
        while(k>0 &&!res.empty()){
            res.pop_back();
            k--;
        }

        //remove the leading zeros 
        int start = 0;
        while(start <res.size() && res[start] == '0'){
            start++;
        }
        res = res.substr(start);

        if(res.empty()){
            return "0";
        }
        else 
            return res;
        
    }
};