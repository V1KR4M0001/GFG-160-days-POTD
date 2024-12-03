  PROBLEM STATEMENT :->
// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.
// Note: A palindrome string is a sequence of characters that reads the same forward and backward.


// Examples:
// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

// Input: s = "aacecaaaa"
// Output: 2
// Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

  
// Constraints:
// 1 <= s.size() <= 106

  PROBELM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome

  SOLUTION :->
//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combine = s + "*" + rev;
        int n = combine.size();
        
        vector<int> lps(n, 0);
        for(int i = 1, len = 0; i < n;) {
            if(combine[i] == combine[len]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else lps[i++] = 0;
        }
        return s.size() - lps[n-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
