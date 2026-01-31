class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters, specials;
        for(char c:s){
            //for charcaters
            if(c>='a' && c<='z'){
                letters.push_back(c);
                
            }
            else
                specials.push_back(c);
        }
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());

        int l = 0, sp =0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >='a' && s[i] <='z')
                s[i]=letters[l++];
            else
                s[i]=specials[sp++];
        }return s;
    }
};