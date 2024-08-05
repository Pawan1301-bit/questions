class Solution {
public:
    bool f(int ind, int n, vector<int>& arr, vector<int>& visited){
        if(ind >= n || ind <0)  
            return false;
        if(arr[ind] == 0)
            return true;

        if(!visited[ind]){
            visited[ind] = 1;
            bool value = f(ind+arr[ind], n, arr, visited) || f(ind-arr[ind], n, arr, visited);
            return value;
            }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n, 0);
        return f(start, n, arr, visited);
    }
};