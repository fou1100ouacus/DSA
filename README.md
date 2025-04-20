C++ Data Structures and Algorithms Repository

Welcome to the C++ Data Structures and Algorithms (DSA) Repository! This project hosts solutions to common DSA problems implemented in C++, designed for competitive programmers, students, and interview candidates. Solutions leverage the C++ Standard Template Library (STL) with a focus on clarity and efficiency.

Purpose

This repository provides:





Clear C++ solutions to DSA problems



Problem descriptions and test cases



Time and space complexity analysis



Example implementations using STL (e.g., std::vector, std::stack)

Problem Categories

Key DSA topics and example problems:

1. Arrays





Examples: Two Sum, Rotate Array



Concepts: Two-pointer, sliding window



Note: Includes problems like array rotation, previously explored in C#.

2. Stacks





Examples: Valid Parentheses, Asteroid Collision



Concepts: LIFO, collision simulation



Featured: Asteroid Collision





Description: Given a vector of integers (positive for right-moving asteroids, negative for left-moving), simulate collisions. The larger asteroid survives (by absolute value), or both are destroyed if equal.



Approach: Use std::stack<int> to track asteroids. Push if no collision (same direction or empty stack). For collisions, compare sizes and pop/discard based on rules.



Complexity: O(n) time, O(n) space



Code: See src/asteroidCollision.cpp (uses <bits/stdc++.h>, std::vector).

3. Linked Lists





Examples: Merge Two Sorted Lists, Reverse Linked List



Concepts: Pointer manipulation, merging



Note: Includes problems like merging sorted lists, previously discussed.

4. Trees





Examples: Inorder Traversal, Validate BST



Concepts: Recursion, DFS

5. Graphs





Examples: BFS, Dijkstra’s Algorithm



Concepts: Adjacency lists, shortest paths

6. Sorting and Searching





Examples: Quick Sort, Binary Search



Concepts: Divide and conquer

7. Dynamic Programming





Examples: Knapsack, Longest Common Subsequence



Concepts: Memoization

8. Greedy Algorithms





Examples: Activity Selection



Concepts: Greedy choice
