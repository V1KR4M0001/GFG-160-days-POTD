  PROBLEM STATEMENT :->
// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.


// Examples:
// Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
// Explanation: 

// Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
// Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
// Explanation: Applying same technique as shown above.

// Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
// Output: [32, 44, 27, 23, 62, 50, 28, 54]
// Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].


// Constraints:
// 1 <= n, m <= 1000
// 0 <= mat[i][j]<= 100

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621

  SOLUTION :-> 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> ans;
        int top = 0;
        int bottom = mat.size()-1;
        int left = 0;
        int right = mat[0].size()-1;
        
        while(top <= bottom && left <= right) {
            for(int i = left ; i <= right; i++) {
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int j = top; j <= bottom; j++) {
                ans.push_back(mat[j][right]);
            }
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(mat[bottom][i]);
                }
            }
            bottom--;
            if(left <= right) {
                for(int j = bottom; j >= top; j--) {
                    ans.push_back(mat[j][left]);
                }
            }
            left++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
