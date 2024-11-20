  PROBLEM STATEMENT :->
//   You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 
// Note: The answer should be returned in an increasing format.

// Examples:
// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.

// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: no candidate occur more than n/3 times.

// Constraint:
// 1 <= arr.size() <= 106
// -109 <= arr[i] <= 109
  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote
  
  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        map<int, int> um;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            um[arr[i]]++;
        }
        vector<int> ans;
        for (auto it : um) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
