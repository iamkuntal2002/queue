#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/diagonal-traverse-ii/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>res;
        queue<pair<int,int>> qu;
        qu.push({0,0});
        while(!qu.empty()){
            auto pr = qu.front();
            qu.pop();
            res.push_back(nums[pr.first][pr.second]);
            //push only down and left side element so that same element won't push twice
            if(pr.second == 0 && pr.first+1<n) qu.push({pr.first+1,pr.second});   //if first col
            if(pr.second+1 < nums[pr.first].size()) qu.push({pr.first,pr.second+1});    //if neighbout element is exist
        }
        return res;
    }
};