  PROBLEM STATEMENT :->
// You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.


// Examples:
// Input: mat[][] = [[1, -1, 1],
//                 [-1, 0, 1],
//                 [1, -1, 1]]
// Output: [[1, 0, 1],
//         [0, 0, 0],
//         [1, 0, 1]]
// Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.

// Input: mat[][] = [[0, 1, 2, 0],
//                 [3, 4, 5, 2],
//                 [1, 3, 1, 5]]
// Output: [[0, 0, 0, 0],
//         [0, 4, 5, 0],
//         [0, 3, 1, 0]]
// Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.


// Constraints:
// 1 ≤ n, m ≤ 500
// - 231 ≤ mat[i][j] ≤ 231 - 1

  PROBLEM LINK :->  https://geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/set-matrix-zeroes

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        bool row_first = 0;
        bool col_first = 0;
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 0) {
                col_first = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(mat[0][i] == 0) {
                row_first = true;
                break;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            }
        }
        if(row_first) {
            for(int i = 0; i < m; i++) mat[0][i] = 0;
        }
        if(col_first) {
            for(int i = 0; i < n; i++) mat[i][0] = 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
