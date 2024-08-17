class Solution {
public:
    int candy(vector<int>& arr) {

        int n = arr.size(), k=1;
        vector<int> left(n), right(n);

        left[0] = 1, right[n-1] = 1;

        for(int i=1; i<n; i++){
            if(arr[i-1] < arr[i]){
                left[i] = ++k;
            }else{
                left[i] = 1;
                k=1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1]){
                right[i] = ++k;
            }else{
                right[i] = 1;
                k=1;
            }
        }

        int min_candy = 0;
        int it =0;
        while(it < n){
            min_candy += max(left[it], right[it]);
            it++;
        }
        return min_candy;
    }
};