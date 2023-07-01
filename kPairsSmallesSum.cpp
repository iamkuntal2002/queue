#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if(k == 0) return ans;
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i =0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(!pq.empty() && k--){
            int i = pq.top().second.first;
            int j =pq.top().second.second;
            cout<<pq.top().first;
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();
            if(j+1<m){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};