// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> store;
        int n = val.size();
        for(int i = 0; i < n; i++) {
            double x = (double)val[i] / wt[i];
            store.push_back({x, i});
        }
        sort(store.rbegin(), store.rend());

        int i = 0;
        double profit = 0;
        
        while(capacity > 0 && i < n) {
            int idx = store[i].second;
            
            if(capacity >= wt[idx]) {
                profit += val[idx];
                capacity -= wt[idx];
                i++;
            }
            else {
                profit += (double)(capacity * val[idx]) / wt[idx];
                i++;
                capacity = 0;
            }
        }
        
        return profit;
        
    }
};
