#include <iostream>

struct stack_node
{
	int data;
	stack_node* next;
};

class Stack
{
private:
	stack_node* top;
public:
	Stack()
	{
		top = NULL;
	}
	void push(int s)
	{
		stack_node* temp = new stack_node;
		(*temp).data = s;
		(*temp).next = top;
		top = temp;
	}
	void pop()
	{
		stack_node* temp = new stack_node;
		temp = top;
		if (top == NULL)
		{
			std::cout << "empty";
			return;
		}
		else
		{
			temp = top;
			top = (*top).next;
			delete(temp);
		}
	}
	void display()
	{
		stack_node* temp = new stack_node;
		if (top == NULL)
		{
			std::cout << "empty";
			return;
		}
		else
		{
			temp = top;
			while (temp != NULL)
			{
				std::cout << (*temp).data << std::endl;
				temp = (*temp).next;
			}
		}
	}
};


int main()
{
	Stack stck;
	stck.push(12);
	stck.push(65);
	stck.push(81);
	stck.push(48);
	std::cout << "before pop " << std::endl;
	stck.display();

	stck.pop();
	std::cout << "After pop" << std::endl;
	stck.display();

	return 0;
}
