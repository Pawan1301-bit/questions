class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){ 
        return (a[0] < b[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), comparator); //nlogn

        vector<vector<int>> merge;
        vector<int> prev = intervals[0];

        for(int i=1; i<n; i++){   //n
            vector<int> interval = intervals[i];
            if(interval[0] <= prev[1]){
                prev[1] = max(interval[1], prev[1]);
            }
            else{
                merge.push_back(prev);
                prev = interval;
            }
        }
        merge.push_back(prev);
        return merge;
    }
};