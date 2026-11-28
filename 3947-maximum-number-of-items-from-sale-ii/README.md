
# 3947. Maximum Number of Items From Sale II

**Difficulty:** Medium

[LeetCode Problem](https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/)

## Approach: Greedy + Sorting + Divisibility Counting

The objective is to maximize the number of items obtained while staying within the given budget.

Each purchased copy can provide at most one free copy of another item whose factor is divisible by the purchased item's factor.

For each item type, we calculate how many other item types it can provide for free.

### 1. Divisibility Counting

Use a frequency array to count how many items have each factor.

For every factor `i`, iterate through its multiples and calculate:

`freq[i] = number of items whose factors are divisible by i`

Subtract one to exclude the item itself:

`cnt = freq[factor] - 1`

This gives the number of free copies that can be obtained by purchasing copies of that item type.

### 2. Sorting by Price

Sort the items in ascending order of price.

For each item, its first `cnt` purchased copies can each provide one additional free item.

Therefore, these purchases effectively provide two items for the price of one.

### 3. Greedy Selection

Let `mn` be the minimum item price.

A boosted purchase costing `price` provides two items, while spending the same amount on the cheapest item provides approximately `price / mn` items.

Boosted purchases are worth prioritizing when:

`price <= 2 * mn`

Process these purchases in ascending price order.

For each item:

- Calculate the maximum number of boosted purchases affordable.
- Limit that number to `cnt`.
- Add two items for every boosted purchase.
- Deduct their cost from the budget.

Once the price exceeds twice the minimum price, stop processing boosted purchases.

Finally, spend the remaining budget on additional copies of the cheapest item.

## Algorithm

1. Sort items by ascending price.
2. Find the maximum factor.
3. Build a frequency array of item factors.
4. Count the number of divisible item types for every factor by iterating through multiples.
5. Find the minimum item price.
6. Process items in ascending price order:
   - Stop if `price > 2 * minimumPrice`.
   - Calculate `cnt = freq[factor] - 1`.
   - Purchase as many boosted copies as the budget and `cnt` allow.
   - Add two items per boosted purchase.
7. Use the remaining budget to purchase the cheapest item.
8. Return the total number of items.

## Complexity Analysis

Let `n` be the number of items and `M` be the maximum factor.

- **Sorting:** `O(n log n)`
- **Divisibility counting:** `O(M log M)`
- **Greedy selection:** `O(n)`
- **Space:** `O(M)`

Since `M <= n`:

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

## Key Concepts

- Greedy
- Sorting
- Divisibility
- Frequency Counting
- Number Theory
