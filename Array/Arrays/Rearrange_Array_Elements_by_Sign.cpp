# Rearrange Array Elements by Sign

## Problem
Given an integer array `nums` containing an equal number of positive and negative integers, rearrange the array such that:

- Every consecutive pair contains one positive and one negative integer.
- Positive integers occupy even indices.
- Negative integers occupy odd indices.
- The relative order of positive and negative numbers is preserved.

## Approach
1. Create a new result array of the same size.
2. Maintain two pointers:
   - `posIndex = 0` for placing positive numbers.
   - `negIndex = 1` for placing negative numbers.
3. Traverse the input array once.
4. If the current element is positive, place it at `posIndex` and increment it by 2.
5. Otherwise, place it at `negIndex` and increment it by 2.
6. Return the rearranged array.

## Algorithm
- Initialize an answer array of size `n`.
- Set:
  - `posIndex = 0`
  - `negIndex = 1`
- Iterate through the array:
  - If the number is positive, place it at `posIndex`.
  - Otherwise, place it at `negIndex`.
- Return the answer array.

## Time Complexity
**O(n)**

## Space Complexity
**O(n)**

## Concepts Used
- Arrays
- Two Pointers
- Simulation
- Traversal

## Status
✅ Solved
