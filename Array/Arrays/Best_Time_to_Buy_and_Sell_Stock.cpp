# Best Time to Buy and Sell Stock (LeetCode 121)

## Problem
You are given an array `prices` where `prices[i]` represents the price of a stock on the `i-th` day.

Your task is to maximize the profit by choosing:
- One day to buy a stock.
- A later day to sell that stock.

Return the maximum profit possible. If no profit can be made, return `0`.

---

## Approach

The idea is to keep track of:

- **Minimum buying price** encountered so far.
- **Maximum profit** that can be obtained by selling on the current day.

### Steps
1. Initialize `minPrice` to a very large value.
2. Traverse the array once.
3. Update the minimum price whenever a smaller price is found.
4. Compute the profit if the stock is sold on the current day.
5. Update the maximum profit if the current profit is larger.
6. Return the maximum profit.

This greedy approach ensures the solution is obtained in a single traversal.

---

## Algorithm
1. Set:
   - `minPrice = INT_MAX`
   - `maxProfit = 0`
2. Iterate through each stock price:
   - Update `minPrice`.
   - Calculate current profit:
     ```
     profit = currentPrice - minPrice
     ```
   - Update `maxProfit`.
3. Return `maxProfit`.

---

## Time Complexity

**O(n)**

Only one traversal of the array is required.

---

## Space Complexity

**O(1)**

No extra data structures are used.

---

## Concepts Used

- Arrays
- Greedy Algorithm
- Single Pass Traversal
- Minimum Tracking

---

## Status

✅ Solved
