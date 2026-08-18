class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five =0, ten = 0;
        for(int i =0;i<n;i++){
            int money = bills[i];
            if(money == 5){
                five++;
            }
            else if(money == 10){
                if(five==0){
                    return false;
                }
                five--;
                ten++;
            }
            else{
                if(ten>0 && five>0){ //choice 1
                    ten--;
                    
                    five--;
                }
                else if(five<3){
                    return false;
                }
                else{
                    five = five-3;}

                
            }

        }
        return true;


        
    }
};