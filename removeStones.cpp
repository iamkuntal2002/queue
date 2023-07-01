#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-stones-to-minimize-the-total/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> qu(piles.begin(),piles.end());
        for(int i =0;i<k;i++){
            int stone = qu.top();
            qu.pop();
            qu.push(stone-(stone/2));
            
        }
        int ans =0;
        while(!qu.empty()){
            ans += qu.top();
            qu.pop();
        }
        return ans;
    }
};