//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comparator(Job &arr1, Job &arr2){
        return (arr1.profit > arr2.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sorting the array based on the decreasing value of profit
        sort(arr, arr+n, comparator);
        
        int maxi  = 0 ; //for storing the last deadline 
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i].dead);
        }
        
        vector<int> check(maxi+1, -1);
        
        //iterating throught the jobs
        int cnt =0, total_profit= 0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(check[j]== -1){
                    check[j] = arr[i].dead;
                    total_profit += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return vector<int>({cnt, total_profit});
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends