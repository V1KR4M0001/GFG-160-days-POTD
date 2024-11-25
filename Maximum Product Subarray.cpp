  PROBLEM STATEMENT :->
// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.
// Note: It is guaranteed that the output fits in a 32-bit integer.

// Examples
// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

// Input: arr[] = [-1, -3, -10, 0, 60]
// Output: 60
// Explanation: The subarray with maximum product is {60}.

// Input: arr[] = [2, 3, 4] 
// Output: 24 
// Explanation: For an array with all positive elements, the result is product of all elements. 

// Constraints:
// 1 ≤ arr.size() ≤ 106
// -10  ≤  arr[i]  ≤  10

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/maximum-product-subarray3604

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int left = 1, right = 1;
        int n = arr.size();
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            left *= arr[i];
            maxLeft = max(maxLeft, left);
            if(left == 0) left = 1;
        }
        for(int i = n-1; i >= 0; i--) {
            right *= arr[i];
            maxRight = max(maxRight, right);
            if(right == 0) right = 1;
        }
        return max(maxLeft, maxRight);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
