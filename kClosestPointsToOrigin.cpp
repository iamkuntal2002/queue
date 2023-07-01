#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    double distance(vector<int> &v){
        int x1 =0;
        int y1 =0;
        int x2 = v[0];
        int y2 = v[1];
        int X = pow((x1-x2),2);
        int Y = pow((y1-y2),2);
        return (double)sqrt((X+Y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double,vector<int>>> vp;
        for(auto v : points){
            double dist = distance(v);
            vp.push_back({dist,v});
        }
        sort(vp.begin(),vp.end());
        vector<vector<int>> res;
        int i =0;
        while(i<k){
            auto pr = vp[i];
            res.push_back(pr.second);
            i++;
        }
        return res;
    }
};