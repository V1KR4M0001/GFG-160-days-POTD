  PROBLEM STATEMENT:->
// Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

// Cases for atoi() conversion:
// Skip any leading whitespaces.
// Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
// Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
// If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.

// Examples:
// Input: s = "-123"
// Output: -123
// Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer

// Input: s = "  -"
// Output: 0
// Explanation: No digits are present, therefore the returned answer is 0.

// Input: s = " 1231231231311133"
// Output: 2147483647
// Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.

// Input: s = "-999999999999"
// Output: -2147483648
// Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.

// Input: s = "  -0012gfg4"
// Output: -12
// Explanation: Nothing is read after -12 as a non-digit character ‘g’ was encountered.

// Constraints:
// 1 ≤ |s| ≤ 15

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans="";
        int i = s1.size()-1;
        int j = s2.size()-1;
        int carry = 0;
        while(i >= 0 || j >= 0) {
            int count1s = 0;
            if(i >= 0 && s1[i] == '1') count1s++;
            if(j >= 0 && s2[j] == '1') count1s++;
            
            if(count1s + carry == 0) {
                ans += '0';
                carry = 0;
            }
            else if(count1s + carry == 1) {
                ans += '1';
                carry = 0;
            }
            else if(count1s + carry == 2) {
                ans += '0';
                carry = 1;
            }
            else if(count1s + carry == 3) {
                ans += '1';
                carry = 1;
            }
            i--;
            j--;
        }
        if(carry == 1) {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        while(ans[i] == '0') {
            ans.erase(0, 1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
