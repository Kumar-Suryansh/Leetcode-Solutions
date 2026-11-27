
# 3946. Maximum Number of Items From Sale I

**Difficulty:** Medium

[LeetCode Problem](https://leetcode.com/problems/maximum-number-of-items-from-sale-i/)

## Approach: Dynamic Programming (0/1 Knapsack)

The first purchase of an item type is special because it gives one free copy of every other item whose factor is divisible by the selected item's factor.

Buying additional copies of an already activated item type does not provide additional free items.

We can model the first purchase of each item type using 0/1 Knapsack:

- **Weight:** Price of the item.
- **Value:** Number of items obtained from the first purchase, including the purchased item and its free copies.
- **DP state:** `dp[j]` represents the maximum number of items obtained using a first-purchase budget of at most `j`.

For each item, count all item factors divisible by its factor. This count includes the selected item itself, representing its purchased copy.

Process the DP array in descending order to ensure each item type is activated only once.

After selecting the first purchases, use the remaining budget to purchase additional copies of the cheapest item.

For every possible first-purchase budget `j`, calculate:

`dp[j] + (budget - j) / minimumPrice`

The maximum value is the answer.

## Algorithm

1. Initialize a DP array of size `budget + 1` with zeros.
2. Find the minimum item price.
3. For each item:
   - Count the item types whose factors are divisible by its factor.
   - Perform a descending 0/1 Knapsack update.
4. Iterate through every possible budget allocation.
5. Add the maximum number of additional cheapest items affordable.
6. Return the maximum total.

## Complexity Analysis

Let `n` be the number of item types and `B` be the budget.

- **Time Complexity:** `O(n² + nB)`
- **Space Complexity:** `O(B)`

## Key Concepts

- Array
- Dynamic Programming
- Greedy
- 0/1 Knapsack
- 
