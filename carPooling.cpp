#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/car-pooling/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto trp : trips){
            int pass = trp[0];
            int to = trp[1];
            int from = trp[2];
            mp[to] += pass;
            mp[from] -= pass;
        }
        for(auto pr : mp){
            capacity -= pr.second;
            if(capacity <0) return false;
        }
        return true;
    }
};