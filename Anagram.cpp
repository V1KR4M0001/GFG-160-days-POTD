  PROBLEM STETEMENT:->
// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.
// Note: You can assume both the strings s1 & s2 are non-empty.

// Examples :
// Input: s1 = "geeks", s2 = "kseeg"
// Output: true
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.

// Input: s1 = "allergy", s2 = "allergic"
// Output: false
// Explanation: Characters in both the strings are not same, so they are not anagrams.

// Input: s1 = "g", s2 = "g"
// Output: true
// Explanation: Character in both the strings are same, so they are anagrams.

// Constraints:
// 1 ≤ s1.size(), s2.size() ≤ 105

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        if(s1.size() != s2.size()) return false;
        
        vector<int> freq(2, 0);
        for(int i = 0; i < s1.size(); i++) {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
