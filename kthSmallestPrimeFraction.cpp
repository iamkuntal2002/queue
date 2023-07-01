#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-th-smallest-prime-fraction/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
         priority_queue<pair<float,pair<int,int>> , vector<pair<float,pair<int,int>>>, greater<pair<float,pair<int,int>>> > qu;
        for(int i =0;i<arr.size()-1;i++){
            for(int j = i+1;j<arr.size();j++){
                float frac = arr[i]*1.0/arr[j];
                qu.push({frac,{arr[i],arr[j]}});
                // if(qu.size()>k-1) qu.pop();
            }
        }
        while(k-1){
            qu.pop();
            k--;
        }
        return {qu.top().second.first,qu.top().second.second};
    }
};