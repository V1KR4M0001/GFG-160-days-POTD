  PROBLEM STATEMENT :->
// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 


// Examples:
// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.


// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

  PROBLEM LINK :-> https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620

  SOLUTION :->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int merge(vector<int>& arr, int left, int mid, int  right) {
        int count = 0;
        vector<int> temp;
        int i = left, j = mid+1;
        
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                count += mid + 1 - i;
                temp.push_back(arr[j++]);
            }
        }
        
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= right) temp.push_back(arr[j++]);
        for(int k = left; k <= right; k++) arr[k] = temp[k - left];
        
        return count;
    }
    
    int mergeSort(vector<int>& arr, int left, int right) {
        if(left >= right) return 0;
        
        int mid = left + (right - left)/2;
        int count = 0;
        
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid+1, right);
        count += merge(arr, left, mid, right);
        
        return count;
    }
  
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
