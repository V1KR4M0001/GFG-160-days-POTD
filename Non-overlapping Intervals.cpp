  PROBLEM STATEMENT:->
// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


// Examples:
// Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Output: 1
// Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

// Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
// Output: 2
// Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.

// Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
// Output: 0
// Explanation: All ranges are already non overlapping.


// Constraints:
// 1 ≤ intervals.size() ≤  105
// |intervalsi| == 2
// 0 ≤ starti < endi <=5*104

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int deleteCount = 0;
        sort(intervals.begin(), intervals.end());
        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < prev) {
                deleteCount++;
                prev = min(prev,intervals[i][1]);
            } else {
                prev = intervals[i][1];
            }
        }
        return deleteCount;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
