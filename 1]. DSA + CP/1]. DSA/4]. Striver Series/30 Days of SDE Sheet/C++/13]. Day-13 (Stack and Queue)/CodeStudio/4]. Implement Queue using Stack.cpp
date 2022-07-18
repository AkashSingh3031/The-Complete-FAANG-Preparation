#include<bits/stdc++.h>
class Queue {
    stack<int> s1;
    stack<int> s2;
public:
    Queue() { }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek() {
         if(s1.empty()){
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool isEmpty() {
        return s1.empty();
    }
};