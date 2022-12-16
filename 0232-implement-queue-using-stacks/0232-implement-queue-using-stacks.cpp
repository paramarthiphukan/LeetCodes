class MyQueue
{
private: stack<int> st;
public:
	MyQueue() 
    {

	}

	void push(int x) 
    {
		if (st.empty()) 
        {
			st.push(x);
			return;
		}
		int temp = st.top();
		st.pop();
		push(x);
		st.push(temp);
	}

	int pop()
    {
        int peek = st.top();
         st.pop();
		return peek;
	}

	int peek() 
    {
		int peek = st.top();
		return peek;
	}

	bool empty()
    {
		return st.empty();
	}
};
