#include <bits/stdc++.h> 
class TwoStack {

public:
    int* arr;
    int size;
    int top1;
    int top2;

    
    void push1(int num) {
        // Write your code here.
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    
    }

   // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else return -1;
    }

        // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else return -1;
        // Write your code here.
    }
};
