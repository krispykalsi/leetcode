//
// Created by I$K on 20/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }

        int buy = 0, sell = 1;
        int profit = 0, netProfit = 0;

        const int SIZE = prices.size();
        while (sell < SIZE) {
            if (prices[buy] > prices[sell] && profit == 0) {
                ++sell;
                ++buy;
            } else {
                int currentProfit = prices[sell] - prices[buy];
                if (currentProfit > profit) {
                    profit = currentProfit;
                } else {
                    netProfit += profit;
                    buy = sell;
                    profit = 0;
                }
                ++sell;
            }
        }

        return netProfit + profit;
    }
};
