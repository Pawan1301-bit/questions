class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sorting the numbers
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        //declaration::
        int n1 = g.size(), n2 = s.size();
        int count = 0, i = n1-1, j = n2-1;

        while(i > -1 && j > -1){
            if(g[i] > s[j]){
                i--;
            }else{
                count++;
                j--,i--;
            }
        }
        return count;
    }
};
