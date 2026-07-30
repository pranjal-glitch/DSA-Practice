# Maximum Subarray (LeetCode 53)

## Problem
Given an integer array `nums`, find the contiguous subarray with the largest sum and return its sum.

A subarray is a contiguous part of an array.

---

## Approach

This problem is solved using **Kadane's Algorithm**, which efficiently finds the maximum sum subarray in a single traversal.

### Steps
1. Initialize:
   - `currSum = 0`
   - `maxSum = INT_MIN`
2. Traverse the array.
3. Add the current element to `currSum`.
4. Update `maxSum` if `currSum` is greater.
5. If `currSum` becomes negative, reset it to `0` since a negative sum cannot contribute to a larger future subarray.
6. Return `maxSum`.

Kadane's Algorithm works because a negative running sum will only decrease the sum of any future subarray.

---

## Algorithm
1. Initialize `currSum = 0` and `maxSum = INT_MIN`.
2. For each element in the array:
   - Add it to `currSum`.
   - Update `maxSum`.
   - If `currSum < 0`, reset `currSum` to `0`.
3. Return `maxSum`.

---

## Time Complexity

**O(n)**

The array is traversed only once.

---

## Space Complexity

**O(1)**

Only two integer variables are used.

---

## Concepts Used

- Arrays
- Kadane's Algorithm
- Dynamic Programming (Optimization)
- Greedy
- Prefix Sum Idea

---

## Key Insight

If the running sum becomes negative, it is better to start a new subarray from the next element because a negative prefix can only reduce the total sum.

---

## Status

✅ Solved
