class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //the core idea in this is that we traverse through the bacskets one and assign the first one that is more than the fruits one and then mark it -1 and also change the bool value in the fruits one to true since it got placed. if it not placed then we obviously count in the the lower if statement of not placed.
        int n =fruits.size();
        int unplaced =0;

        for(int i=0;i<n;++i){
            bool placed = false;
            for(int j = 0;j<n;++j){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1; //this will always less than any number so the already asssigned basket will not be assigned to the fruits in any case 
                    placed =true;
                    break;

                }
            }
            if(!placed){
                unplaced++;
            }
        }
        return unplaced;
        
    }
};