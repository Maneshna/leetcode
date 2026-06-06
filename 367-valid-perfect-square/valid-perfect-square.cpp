class Solution {
public:
    bool isPerfectSquare(int num) {
        //edge case of 1 and 0
        if(num<2)
            return true;
        long left = 1;
        long right = num/2;

        while(left<=right){
            long mid = left+(right-left)/2;
            long guess = mid*mid;

            if(guess== num){
                return true;
            }
            else if(guess>num){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
        
    }
};