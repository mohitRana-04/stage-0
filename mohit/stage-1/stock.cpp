class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()== 1) return 0;
        int l = 0, r = 1;
        int ans = 0;
        while(r<prices.size()){
            if(prices[r]>=prices[l]){
                ans = max(ans, prices[r]-prices[l]);
                r++;
            }
            else{
                l = r;
                r++;
            }
        }
        return ans;
    }
};