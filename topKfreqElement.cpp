#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> qu;
        for(int &e : nums) mp[e]++;
        for(auto pr : mp) {
            qu.push({pr.second,pr.first});
        }       
        while(!qu.empty() && k>0){
            res.push_back(qu.top().second);
            qu.pop();
            k--;
        }
        return res;
    }
};