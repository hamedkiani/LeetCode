class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int sz = height.size();
        if (sz < 2)
            return 0;
        int l = 0;
        int r = sz-1;
        int maxVal = 0;
        while(l < r)
        {
            maxVal = max(maxVal, min(height[l] , height[r])*(r-l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxVal;
    }
};
