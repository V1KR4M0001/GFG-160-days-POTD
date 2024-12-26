  PR0LBLEM STATEMENT :->
// Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.


// Examples:
// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
// Output: true
// Explanation: arr[3] + arr[4] = 6 + 10 = 16.

// Input: arr[] = [1, 2, 4, 3, 6], target = 11
// Output: false
// Explanation: None of the pair makes a sum of 11.

  
// Constraints:
// 1 ≤ arr.size ≤ 105
// 1 ≤ arr[i] ≤ 105
// 1 ≤ target ≤ 2*105

  PROBLEM LINK :->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/key-pair5616


  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            int diff = target - arr[i];
            if(mp.find(diff) != mp.end()) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
