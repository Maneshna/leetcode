class Solution {
public:
    bool isValid(string s) {
        //for this we use stack 
        stack<char> st;
        for(int c:s){
            if(c=='['|| c=='{' || c=='('){
                st.push(c);
            }
            else{

                if(st.empty()) return false; //this means there is no opening parenthsis so it can never be valid 

                char top = st.top();
                st.pop();
                //now we pop the top elements (which should be the opnening parenthesis so we will pop and compare with the remining ones in the array)

                if((c==')' && top != '(')||
                (c=='}' && top != '{') ||
                (c==']' && top!= '[')){
                    return false;
                }

            }
        }
        return st.empty();

        
    }
};