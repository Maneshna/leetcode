class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;

        int n = num.length();
        for(int i =n; i>=0; i--){
            if((num[i]-'0')%2==1){
                index = i;
                break;
            }
        }

        int i =0;
        while(i<=n && num[i]==0){
            i++;
        }

        return num.substr(i, index-i+1);

        
    }
};