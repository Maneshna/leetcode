class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //make a stack 
        vector<int> stack;

        for(int asteroid : asteroids){
            bool destoryed = false;

            while(!stack.empty() && stack.back() >0 && asteroid <0){
                if(stack.back() < -asteroid){
                    stack.pop_back();
                }
                else if(stack.back() == -asteroid){
                    stack.pop_back();
                    destoryed = true;
                    break;
                }
                else{
                    destoryed = true;
                    break;
                }
            }
            if(!destoryed){
            stack.push_back(asteroid);
        }
        
        }
        return stack;
        
        
    }
    
};