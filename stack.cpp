#include <iostream>

class Stack
{
private:
	int max_size;
	long* stack_array;
	int top;
public:
	Stack(int s) : top(-1), max_size(s)
	{
		stack_array = new long[max_size];
	}

	void push(long j)
	{
		stack_array[++top] = j;
	}
	long pop()
	{
		return stack_array[top--];
	}
	long peek()
	{
		return stack_array[top];
	}
	bool is_empty()
	{
		return (top == -1);
	}
	bool is_full()
	{
		return (top == max_size - 1);
	}
};


int main()
{
	Stack stck(10);
	stck.push(-12);
	stck.push(65);
	stck.push(81);
	stck.push(48);

	while (!stck.is_empty())
	{
		long value = stck.pop();
		std::cout << value << " ";
	}
	return 0;
}