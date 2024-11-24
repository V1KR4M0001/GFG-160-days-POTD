  PROBLEM STATMENT:->
// Given an integer array arr[]. You need to find the maximum sum of a subarray.

// Examples:
// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray {-2} has the largest sum -2.

// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// -109 ≤ arr[i] ≤ 104

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/kadanes-algorithm-1587115620

  SOLUTION :->
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0; /*if sum is negative then no use to carry it further*/
        }
        return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends
