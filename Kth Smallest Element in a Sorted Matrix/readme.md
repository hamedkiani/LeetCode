# LeetCode 378. Kth Smallest Element in a Sorted Matrix

### Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

### Difficulty: Medium

## Description

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
```
  matrix = [
     [ 1,  5,  9],
     [10, 11, 13],
     [12, 13, 15]
  ]
```
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

## Code and Explanation

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
      // this is similar to binary search of a vector (1D array). The main \
       difference is here we are dealing with a 2D matrix which is sorted \
        column and row wise. We do 2D binary search and at each iteration we \
         count the number of element in each row which are smaller than the mid \
          value. If the sum is less than K, then we need to add the low index, \
           otherwise if the sum is more than K, we need to move the high index \
            to the mid index. When low is more than high index, we return the \
             low value.

      int n = matrix.size();
      int L = matrix[0][0], R = matrix[n-1][n-1];
      while (L < R) {
        int mid = L + ((R - L) >> 1);
        int temp = 0;
        for (int i = 0; i < n; i++)
        // upper_bound returns the position of the biggest number whose value \
         is smaller than the given value (mid here)
         temp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
      if (temp < k)
        L = mid + 1;
      else
        R = mid ;
  		}
      return L;
      }
};
```

### Time Complexity
O(N^2): there is a while loop in the worse case can have O(N), and at each loop we have another for loop, with O(N).

### Space Complexity
O(1)

### Useful Links
