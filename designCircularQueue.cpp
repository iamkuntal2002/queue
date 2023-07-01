#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/design-circular-queue/
struct DoubleNode{
    int val;
    DoubleNode *next;
    DoubleNode *prev;
    DoubleNode(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class MyCircularQueue {
public:
    int maxsize = 0;
    DoubleNode *head;
    DoubleNode *curr;
    int size = 0;
    DoubleNode* newNode(int val){
        DoubleNode *node = new DoubleNode(val);
        return node;
    }
    MyCircularQueue(int k) {
        maxsize = k;
        head = NULL;
        curr = head;
    }
    
    bool enQueue(int value) {
        if(size<maxsize){
            DoubleNode *node = newNode(value);
            if(size == 0){
                head = node;
                curr = head;
            }
            else{
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
            }
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size>0){
            curr = curr->prev;
            if(curr != NULL) curr->next = NULL;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(size == 0) return -1;
        return curr->val;
    }
    
    int Rear() {
        if(size ==0) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */