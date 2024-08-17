//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/* 
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool comparator(Item& a, Item& b) {
    return (double(a.value) / a.weight) > (double(b.value) / b.weight);
}

    
    double fractionalKnapsack(int w, Item arr[], int n) {
        // first we will sort the array based on the  values per unit weight
        sort(arr, arr+n, comparator);
        
        double total_profit = 0;
        int i=0;
        
        while(w && i < n){
            if(w >= arr[i].weight){
                total_profit += arr[i].value;
                w -= arr[i].weight;
                i++;
            }else{
                double val = (double(arr[i].value) / arr[i].weight)*w;
                total_profit += val;
                break;
            }
        }
        return total_profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends