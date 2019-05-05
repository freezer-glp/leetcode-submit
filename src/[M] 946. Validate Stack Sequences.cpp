/*
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      if (pushed.empty() || popped.empty() ||
         pushed.size() != popped.size()) return true;
      int i = 0; int j = 0;
      stack<int> s;
      while((i<pushed.size() && j < popped.size())) {
        if (pushed[i] == popped[j] ) {
          i++;
          j++;
        } else {
          if (!s.empty() && popped[j] == s.top()) {
            s.pop();
            j++;
          } else {
            s.push(pushed[i]);
            i++;
          }
        }
      }
      while(!s.empty() && j < popped.size()) {
        if (s.top() == popped[j]) {
          s.pop();
          j++;
        } else {
          return false;
        }
      }
      return s.empty() && j == popped.size();
    }
};