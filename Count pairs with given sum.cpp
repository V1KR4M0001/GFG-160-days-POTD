  PROBLEM STATEMENT :->
// Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.


// Examples:
// Input: arr[] = [1, 5, 7, -1, 5], target = 6 
// Output: 3
// Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 

// Input: arr[] = [1, 1, 1, 1], target = 2 
// Output: 6
// Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

// Input: arr[] = [10, 12, 10, 15, -1], target = 125
// Output: 0


// Constraints:
// 1 <= arr.size() <= 105
// -104 <= arr[i] <= 104
// 1 <= target <= 104

  PROBLEM LINK :->  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, int> mp;
        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            int second = target-arr[i];
            count += mp[second];
            mp[arr[i]]++;
        }
        return count;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
