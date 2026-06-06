class Solution {
public:
    int mySqrt(int x) {
        //edge case 
        if (x < 2) return x;


        long left = 0;
        long right = x;

        while(left<=right){
            long mid = left+ (right-left)/2;
            long guess = mid*mid;

            if(guess==x){
                return mid;
            }
            else if(guess>x){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }return right;
        
    }
};