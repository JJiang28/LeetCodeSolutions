class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = 0;
        for(int i = 1; i < prices.size(); i++) {
            if((prices[i] - prices[buy]) > maxProfit) {
                maxProfit = prices[i] - prices[buy];
            } 
            while((prices[i] - prices[buy]) < 0){
                buy++;
            }
        }
        return maxProfit;
    }
};