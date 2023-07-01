#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reduce-array-size-to-the-half/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int res =0;
        int rmv =0;
        unordered_map<int,int> mp;
        priority_queue<int> qu;
        for(int &e : arr) mp[e]++;
        for(auto pr : mp) qu.push(pr.second);
        while(rmv < n/2){
            rmv+= qu.top();
            qu.pop();
            res++;
        }
        return res;
    }
};