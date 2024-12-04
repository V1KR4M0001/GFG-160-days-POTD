  PROBLEM STATEMENT :->
// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.
// Note: The characters in the strings are in lowercase.


// Examples :
// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.

// Input: s1 = "aab", s2 = "aba"
// Output: true
// Explanation: After 1 left rotation, s1 will become equal to s2.

// Input: s1 = "abcd", s2 = "acbd"
// Output: false
// Explanation: Strings are not rotations of each other.


// Constraints:
// 1 <= s1.size(), s2.size() <= 105

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string str = s2 + '$' + s1 + s1;
        int n = str.length(), i = 0, j = 1, m = s2.length();
        vector<int> lps(n, 0);
        while(j < n) {
            if(str[i] == str[j]){
                lps[j++] = ++i;
                if(i == m) return true;
            } else if(i) {
                i = lps[i-1];
            } else{
                j++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
