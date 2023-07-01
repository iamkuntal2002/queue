#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/product-of-the-last-k-numbers/
class ProductOfNumbers {
public:
    vector<int> st;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
        int n = st.size()-1;
        int res = 1;
        while(k--){
            res *= st[n--];
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */