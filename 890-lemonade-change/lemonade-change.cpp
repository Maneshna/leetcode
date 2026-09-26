class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int ten, five =0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five ==0){
                    return false;
                }
                five--;
                ten++;
            }
            else{
                if(ten>0 &&five>0){
                    ten--;
                    five--;
                }
                else if(five <3){
                    return false;
                }
                else{
                    five = five-3;
                }
            }
        }
        return true;
        
    }
};