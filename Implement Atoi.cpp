  PROBLEM STATEMENT :->
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

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i = 0, sign = 1;
        long ans = 0;
        
        while(s[i] == ' ') i++;
        if(s[i] =='+'|| s[i] =='-') {
            if(s[i]=='-') {
                sign *= -1;
            }
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9') {
            ans = ans*10 + (s[i]-'0');
            if(sign*ans >= INT_MAX) return INT_MAX;
            if(sign*ans <= INT_MIN) return INT_MIN;
            i++;
        }
        return (int)sign*ans;   
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
