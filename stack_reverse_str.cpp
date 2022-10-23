#include <iostream>

class Stack_reverse_string
{
private:
	int top;
	unsigned int max_size;
	char* array;
public:
	Stack_reverse_string(unsigned int size) : max_size(size), top(-1)
	{
		array = new char[size * sizeof(char)];
	}

	bool is_full()
	{
		return top == max_size - 1;
	}

	int is_empty()
	{
		return top == 1;
	}

	void push(char j)
	{
		array[++top] = j;
	}
	char pop()
	{
		return array[top--];
	}

	void reverse_str(char str[])
	{
		int n = strlen(str);
		//Stack_reverse_string stack(n);

		for (int i = 0; i < n; i++)
		{
			push(str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			str[i] = pop();
		}
	}
};


int main()
{
	char str[] = "Green Clown is relax boi";
	int len = strlen(str);
	Stack_reverse_string stack(len);
	stack.reverse_str(str);
	std::cout << "Reversed string: " << str;

	return 0;
}