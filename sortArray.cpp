#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
    int partition(vector<int> &nums,int low,int high){
        int pivot = nums[high];
        int i = (low- 1);
        for (int j = low; j <= high - 1; j++) {
            if (nums[j] < pivot) {
                i++; 
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return (i + 1);
    }
    void quickSort(vector<int> &nums,int left,int right){
        if(left < right){
            int pivot = partition(nums,left,right);
            quickSort(nums,left,pivot-1);
            quickSort(nums,pivot+1,right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};