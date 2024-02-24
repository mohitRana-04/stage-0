class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int bucket[] = {-1};
        int votes = 0;
        for(int i =0; i< nums.size(); i++){
            if(bucket[0] == -1){
                bucket[0] = nums[i];
                votes++;
            }
            else if(bucket[0] == nums[i]){
                votes++;
            }else{
                votes--;
                if(votes == 0) bucket[0]=-1;
                
            }
        }
        return bucket[0];
    }
};