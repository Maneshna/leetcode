class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector <int> st;
        for(int i =0;i<s.length(); i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop_back();
                }
                else{
                    s[i] = '#';
                }
            }
        }
        for(int index: st){
            s[index] = '#';
        }

        string result ="";
        for(char c:s){
            if(c != '#'){
                result += c;
            }
        }
        return result;
        
    }
};