class Solution {
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n= s.length();
        //first we will  check for ')' if we have sufficient  
        int c=0,p=0;
        for(int i=0; i<n; i++){
            if(s[i] == '*')   c++;
            p += (s[i] == '(') - (s[i] == ')');

            if(p < 0)   c--, p++;   //we have extra close bracket
            if(c < 0)   return false;
        }

        //we will check for '('
        c=0,p=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '*') c++;
            p += (s[i] == '(') - (s[i] == ')'); 

            if(p > 0)   c--,p--; //we have extra open bracket
            if(c < 0)   return false;
        }

        return true;
       }
};