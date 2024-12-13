  PROBLEM STATEMENT :->
// A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 


// Examples:
// Input: arr[] = [5, 6, 1, 2, 3, 4]
// Output: 1
// Explanation: 1 is the minimum element in the array.

// Input: arr[] = [3, 1, 2]
// Output: 1
// Explanation: Here 1 is the minimum element.

// Input: arr[] = [4, 2, 3]
// Output: 2
// Explanation: Here 2 is the minimum element.


// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 109

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n = arr.size(), low = 0, high = n-1, mid;
        while(low < high) {
            mid = (low+high) / 2;
            if(arr[mid] <= arr[high]) high = mid;
            else low = mid + 1;
        }
        return arr[low];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
