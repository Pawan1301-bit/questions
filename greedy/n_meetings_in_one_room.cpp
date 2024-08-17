class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool comparator(vector<int>& a, vector<int>& b){
        return (a[1] < b[1]);
    }
    
    int maxMeetings(int n, int start[], int end[]) {
        
        if(n == 1)  return 1;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<n; i++)
            arr.push_back({start[i], end[i]});
            
        sort(arr.begin(), arr.end(), comparator);
        
        int end_time = arr[0][1], cnt =1;
        for(int i=1; i<n; i++){
            if(end_time < arr[i][0]){
                cnt++;
                end_time = arr[i][1];
            }
        }
        return cnt;
        
    }
};