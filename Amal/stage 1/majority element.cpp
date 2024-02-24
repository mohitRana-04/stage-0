class Solution {
public:
    int majorityElement(vector<int> v) {
        map<int,int>mpp;
        for(int i=0; i<v.size(); i++){
            mpp[v[i]]++;
        }
        for(auto it:mpp){
            if(it.second > (v.size()/ 2)){
                return it.first;
            }
        }
        return -1;
        
    }
};

// ye key-value pair se kiya hai kyuki mujhe moore voting
// algorithm samaj nhi aa raha tha