class Solution {
public:

    string process(string str){
        stack<char> st;
        for(char c:str){
            if(c=='#'){
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(c);
            }
        }
        string result="";
        while(!st.empty()){
            result += st.top();
            st.pop();

        }
        return result;
    }
    bool backspaceCompare(string s, string t) {
        return process(s)== process(t);
        
        
    }
};