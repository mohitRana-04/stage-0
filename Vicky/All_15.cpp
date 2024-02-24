class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<pair<int,int>>cor;
        // int x=-1,y=-1,m=matrix.size(), n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             cor.push_back({i,j});
        //         }
        //     }
        // }
        // for(auto &i:cor){
        //     x=i.first; y=i.second;
        //     for(int j=0;j<m;j++)
        //         matrix[j][y]=0;
        //     for(int j=0;j<n;j++)
        //         matrix[x][j]=0;
        // }

        int x=-1,y=-1,m=matrix.size(),n=matrix[0].size();
        vector<pair<int,int>>cor;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    cor.push_back({i,j});
                }
            }
        }
        for(auto &i:cor){
            x=i.first;y=i.second;
            for(int j=0;j<n;j++)
                matrix[x][j]=0;
            for(int j=0;j<m;j++)
                matrix[j][y]=0;
        }

        // int m=matrix.size(), n=matrix[0].size();
        // int row[m], col[n];
        // for(auto &i:row)i=0;
        // for(auto &i:col)i=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=1;
        //             col[j]=1;
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(row[i]||col[j]){
        //             matrix[i][j]=0;
        //     }
        // }
    }
};

//2
class Solution {
public:
    int nCr(int n, int r){
        long long res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return (int)res;
    }
    vector<vector<int>> generate(int num) {
        // 1 more optimize
        vector<vector<int>>result;
        for(int i=1;i<=num;i++){
            vector<int>row;
            for(int j=1;j<=i;j++){
                row.push_back(nCr(i-1,j-1));
            }
            result.push_back(row);
        }
        return result;

        // 2 optimize
    //    vector<vector<int>>r;
    //    for(int i=0;i<num;i++){
    //        long long res=1;
    //        vector<int>ans;
    //        ans.push_back(res);
    //        for(int j=0;j<i;j++){
    //            res=res*(i-j);
    //            res=res/(j+1);
    //            ans.push_back(res);
    //        }
    //        r.push_back(ans);
    //    }
    //    return r;

    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end()); 
            return;    
        }
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
         reverse(nums.begin()+index+1,nums.end());
        return;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),sum=0,mx=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mx)
                mx=max(mx,sum);
            if(sum<0)sum=0;
        }
        return mx;

        // for(int i=0;i<n;i++){
        //     sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         mx=max(mx,sum);
        //     }
        // }
        // return mx;

        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     if(sum>mx){
        //         mx=max(mx,sum);
        //     }
        //     if(sum<0)sum=0;
        // }
        // return mx;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        // best approach Dutch national flag
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0:
                swap(nums[mid++],nums[low++]);
                break;
                case 1:
                mid++;
                break;
                case 2:
                swap(nums[mid],nums[high--]);
                break;
            }
        }        

        // for(int i=1;i<n;i++){
        //     int curr=nums[i];
        //     int j=i-1;
        //     while(j>=0 && nums[j]>curr){
        //         nums[j+1]=nums[j];
        //         j--;
        //     }
        //     nums[j+1]=curr;
        // }
        // return;

        // int hash[3]={0};
        // for(auto &i: nums)
        //     hash[i]++;
        // int i=0;
        // for(i=0;i<hash[0];i++)
        //     nums[i]=0;
        // for(int j=0;j<hash[1];j++)
        //     nums[i++]=1;
        // for(int j=0;j<hash[2];j++)
        //     nums[i++]=2;

    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int i=0,j=1,dif=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j]>prices[i])
        //             dif=max(prices[j]-prices[i],dif);
        //     }
        // }
        // return dif;

        int mn=INT_MAX, mxPro=0;
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            mxPro=max(prices[i]-mn,mxPro);
        }
        return mxPro;
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int m=matrix.size(), n=matrix[0].size();
        // vector<vector<int>>ans(n, vector<int>(m,0));
        // for(int i=0;i<m;i++)
        //     for(int j=n-1,k=0;j>=0;j--,k++){
        //         ans[i][k]=matrix[j][i];
        //     }
        // for(int i=0;i<m;i++)
        //     for(int j=0;j<n;j++)
        //         matrix[i][j]=ans[i][j];

        int i=1,j=1,n=matrix.size();
        while(i<n&&j<n){
            for(int x=i;x>=0;x--)
                swap(matrix[i][x],matrix[x][i]);
            i++;j++;
        }
        for(auto &i:matrix)
            reverse(i.begin(),i.end());
        // for(auto &x:matrix)
        //     for(auto &y:x)cout<<y<<" ";
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n=v.size();
    unordered_map<int,int>mp;
    for(auto &i:v)
        mp[i]++;  
    for(auto &i:v){
        if(mp[i]>1)
            return i;
    }
        return 0;
    }
};

#include <bits/stdc++.h> 

long long getInversions(long long *arr, int n){

    // Write your code here.

    int count = 0;

    for(int i = 0;i<n;i++)

    {

        for(int j = i+1;j<n;j++)

        {

            if(arr[i]>arr[j])

            {

                if(i<j)

                {

                    count = count + 1;

                }

                else

                {

                    continue;

                }

            }

        }

    }

 

    return count;

}




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

class Solution {
    // double fact(double x, int n){
    //     if(n==0)return 1;
    //     if(n%2)
    //     return fact(x*x,n/2)*x;
    //     else
    //         return x*fact(x*x,(n-1)/2);
    // }
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(n<0)nn=-1*nn;
        while(nn){
            if(nn%2)
                ans=ans*x, nn-=1;
            else
                x*=x, nn=nn/2;
        }
        if(n<0)ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n/2];

        //  Boyer-Moore Voting Algorithm:
        int cnt=0;
        int ele, n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }else if(nums[i]==ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele)cnt1++;
        }
        return cnt1>n/2?ele:-1;
    }
};





