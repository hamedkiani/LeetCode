class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
		int L = matrix[0][0], R = matrix[n - 1][n - 1];
		while (L < R) {
			int mid = L + ((R - L) >> 1);
			int temp = 0;
			for (int i = 0; i < n; i++)
                temp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

			if (temp < k)
                L = mid + 1;
			else R = mid ;
		}
		return L;
    }
};
