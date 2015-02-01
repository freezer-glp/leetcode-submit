//Min Stack
/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.*/
class MinStack {
public:
	stack<int > s;
	stack<int> ms;
	int size=0;
    void push(int x) {
		s.push(x);
        if(size == 0){
			ms.push(x);
		}else{
			if(x <= ms.top())//caution：it is <= ,not < only
				ms.push(x);
		}
		size++;
    }

    void pop() {
        int temp = s.top();
		s.pop();
		if(temp == ms.top())
			ms.pop();
		size--;
		
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ms.top();
    }
};