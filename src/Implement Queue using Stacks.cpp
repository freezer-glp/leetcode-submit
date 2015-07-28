/*Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
Hide Tags Stack Data Structure
Show Similar Problems
*/
class Queue {
public:
	stack<int> s;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        int size = s.size() - 1;
		for(int i = 1; i <= size; i++){
			temp.push(s.top());
			s.pop();
		}
		s.pop();
		size = temp.size();
		for(int i = 1; i <= size; i++){
			s.push(temp.top());
			temp.pop();
		}
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        int size = s.size() - 1;
		for(int i = 1; i <= size; i++){
			temp.push(s.top());
			s.pop();
		}
		int p = s.top();
		size = temp.size() ;
		for(int i = 1; i <= size; i++){
			s.push(temp.top());
			temp.pop();
		}
		return p;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};