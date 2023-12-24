class Solution {
private:
    static bool comp (pair <int, int> &a, pair <int, int> &b) {
        return a.first < b.first;
    }
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector <pair<int, int>> stockPrice(n);
        for (int i=0; i < n; ++i) 
            stockPrice[i] = {price[i], i + 1};
        sort(stockPrice.begin(), stockPrice.end(), comp);
        int stocks_buy = 0;
        for (int i=0; i < n; ++i) {
            if (stockPrice[i].first * stockPrice[i].second <= k) {
                stocks_buy += stockPrice[i].second;
                k -= stockPrice[i].first * stockPrice[i].second;
            }
            else {
                stocks_buy+=k/stockPrice[i].first;
                break;
            }
        }
        return stocks_buy;
    }
};
