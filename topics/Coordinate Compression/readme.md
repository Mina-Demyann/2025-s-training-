
# Coordinate Compression and Maximum Customers Problem

This repository contains a solution to a classic competitive programming problem involving coordinate compression and calculating the maximum number of customers present at any given time. The problem is part of Mahmoud_Ayman's sheet available on Codeforces.

## Problem Description

Given a list of intervals with arrival and departure times of customers, we need to determine the maximum number of customers present at any point in time. The challenge lies in handling the large constraints where the time values can be up to \(10^{18}\), but the number of unique intervals is limited to \(10^5\).

## Solution Logic

The solution utilizes coordinate compression to map the large time values to a smaller, manageable range. This allows us to use efficient algorithms to solve the problem within the given constraints.

### Steps

1. **Reading Input**: Collect all arrival and departure times.
2. **Coordinate Compression**: 
    - Sort the collected times and remove duplicates.
    - Map each time to its compressed index.
3. **Event Counting using a Difference Array**:
    - Use a difference array to count the number of customers arriving and departing at each compressed time index.
4. **Prefix Sum Array**:
    - Compute prefix sums of the difference array to find the actual number of customers present at each time.
    - The maximum value in this prefix sum array gives the maximum number of customers present at any time.

## Code

The main solution can be found in the [RestaurantCustomers.cpp](RestaurantCustomers.cpp) file.

## Video Explanations

For a better understanding of coordinate compression, you can refer to the following video tutorials:

1. [Coordinate Compression Explanation by Mahmoud Ayman](https://www.youtube.com/watchv=rDNgHaZVbtc&list=PLIOhtFzqhbbGroes7my01e8x6GtP71Ah4&index=6)
2. [Coordinate Compression Concept by dr.mostafa saad](https://www.youtube.com/watch?v=nqJIXtfs7p4&t=399s)

## Mahmoud_Ayman's Sheet

This problem is part of Mahmoud_Ayman's competitive programming sheet, which can be found on Codeforces (in Algorithms and Techniques): [Mahmoud_Ayman's Sheet](https://codeforces.com/group/9QrbarK7qH/contests)





