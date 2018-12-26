# LeetCode 454. 4Sum II

### Link: https://leetcode.com/problems/4sum-ii/

### Difficulty: Medium

## Description

Given four lists *A*, *B*, *C*, *D* of integer values, compute how many tuples *(i, j, k, l)* there are such that *A[i] + B[j] + C[k] + D[l]* is zero.

To make problem a bit easier, all *A*, *B*, *C*, *D* have same length of *N* where *0 ≤ N ≤ 500*. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:

      A = [ 1, 2]

      B = [-2,-1]

      C = [-1, 2]

      D = [ 0, 2]

Output:
2

Explanation:

The two tuples are:

      1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
      2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

## Code and Explanation

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // count the number of cases that A[i] + B[j] + C[k] + D[l] = 0
        int count = 0;
        // we use an unordered_map to count all possible summations of A and B
        unordered_map<int, int> mp;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                mp[A[i]+B[j]]++;
            }
        }
        // now, we go over C and D and see if any summation of C and D exists in the unordered map
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                if (mp.find(-(C[i] + D[j])) != mp.end()) {
                    count += mp[-(C[i] + D[j])];
                }
            }
        }
        return count;
    }
};
```

### Time Complexity

**O(N^2)**

There are two separate nested loops.

### Space Complexity

**O(N*M)**

N and M are numbers in the selected arrays in the first nested loops. To save memory, you can choose to use the shortest two arrays (A and B, A and C, B and C, B and D) over the first nested loops.

### Useful Links

N/A
