// #include <iostream>
// #include <algorithm>

// class Solution {
// public:
//     void merge(long long arr1[], long long arr2[], int n, int m) {
//         int i = 0, j = 0, k = n - 1;

//         while (i <= k && j < m) {
//             if (arr1[i] <= arr2[j]) {
//                 i++;
//             } else {
//                 swap(arr1[k--], arr2[j++]);
//             }
//         }

//         sort(arr1, arr1 + n);
//         sort(arr2, arr2 + m);
//     }
// };
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};