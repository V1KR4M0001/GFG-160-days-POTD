  PROBLEM STATEMENT:->
// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.


// Examples :
// Input: txt = "abcab", pat = "ab"
// Output: [0, 3]
// Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

// Input: txt = "abesdu", pat = "edu"
// Output: []
// Explanation: There's no substring "edu" present in txt.

// Input: txt = "aabaacaadaabaaba", pat = "aaba"
// Output: [0, 9, 12]
// Explanation:


// Constraints:
// 1 ≤ txt.size() ≤ 106
// 1 ≤ pat.size() < txt.size()
// Both the strings consist of lowercase English alphabets.

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        int k = pat.size();
        vector<int> lps(k, 0), res;
        for(int i = 1, len = 0; i < k;) {
            if(pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if(len) {
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
            
        for(int i = 0, j = 0; i < txt.size();) {
            if(txt[i] == pat[j]) {
                i++, j++;
                if(j == k) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                } 
            } else if(j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
