class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
        for(int i = 0; i< intervals.size(); i++){
            
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                // matlab naya pair toh banega hi
                ans.push_back(intervals[i]);
            }
            else{
                // matlab ander lie kar rha hai
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};