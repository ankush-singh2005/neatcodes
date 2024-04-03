#include <bits/stdc++.h> 
void solve(stack<int>&inputStack,int count, int size){

   //this is the base case where if count is equal to the middle we pop the element
   if(count==size/2){
      inputStack.pop();
      return;

   }

   //storing the top element in a variable
   int num=inputStack.top();
   //poppin the top variable in order to reach the middle element
   inputStack.pop();

   //doing recursive calls 
   solve(inputStack, count+1, size);
   //after poppin the elements we add the num that is the top
   // element back into the array so after popping the midle element of the stack we still hace all the other remaining elements
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   //int size=inputStack.size();
   int count=0;
   solve(inputStack,count,N);
   
}
