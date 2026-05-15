/*Problem: Find Minimum in Rotated Sorted Array

Platform: LeetCode

Problem Statement:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the rotated sorted array containing unique elements, return the minimum element of the array.

You must solve it in O(log n) time complexity using Binary Search.

Example:
Input:
arr = [4,5,6,7,0,1,2]

Output:
0

Explanation:
The original sorted array was:
[0,1,2,4,5,6,7]

After rotation, the minimum element remains 0.
*/

  #include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {

    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {

        int mid = start + (end - start) / 2;

        // Minimum lies in left half including mid
        if(arr[mid] < arr[end]) {
            end = mid;
        }

        // Minimum lies in right half
        else {
            start = mid + 1;
        }
    }

    return arr[start];
}
