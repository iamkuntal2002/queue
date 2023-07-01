#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for(int i =1; i<=n;i++){
            qu.push(i);
        }
        while(qu.size() != 1){
            for(int i =1; i<= k-1; i++){
                qu.push(qu.front());
                qu.pop();
            }
            qu.pop();
        }
        return qu.front();
    }
};