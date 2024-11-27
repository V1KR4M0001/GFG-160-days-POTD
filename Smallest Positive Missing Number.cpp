  PROBLEM STATEMENT :->
// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
// Note: Positive number starts from 1. The array can have negative integers too.

// Examples:
// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.

// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.

// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// Explanation: Smallest positive missing number is 1.

// Constraints:  
// 1 <= arr.size() <= 105
// -106 <= arr[i] <= 106

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/smallest-positive-missing-number-1587115621

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i]-1]) {
                swap(arr[i], arr[arr[i]-1]);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i != arr[i-1]) return i;
        }
        return n+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
