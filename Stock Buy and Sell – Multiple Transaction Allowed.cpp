  PROBLEM STATEMENT :->
//   The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.
// Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.

// Examples:
// Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
// Output: 865
// Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210. Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.

// Input: prices[] = [4, 2, 2, 2, 4]
// Output: 2
// Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.

// Constraints:
// 1 <= prices.size() <= 105
// 0 <= prices[i] <= 104
  
  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615
  
  SOLUTION :->
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit = 0;
        
        for(int i = 0; i < prices.size()-1; i++) {
            if(prices[i+1] > prices[i]) {
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
