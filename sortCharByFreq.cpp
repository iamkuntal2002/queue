#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> qu;
        for(char c : s) mp[c]++;
        for(auto pr : mp) qu.push({pr.second,pr.first});
        string res = "";
        while(!qu.empty()){
            auto pr = qu.top();
            for(int i =0;i<pr.first;i++) res+= pr.second;
            qu.pop();
        }
        return res;
    }
};