class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxVal = 0;
        for(int i = 0; i < prices.size(); i++){
            minVal = min(minVal , prices[i] );
            maxVal = max(maxVal, prices[i]-minVal);
        }
        return maxVal;
    }
};
