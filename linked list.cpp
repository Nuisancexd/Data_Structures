#include <iostream>
#include <string>


struct Node
{
	int age;
	std::string name;
	Node* next;
};

class List
{
public:
	Node* head;
	int size;
public:
	List() : size(0)
	{
		head = NULL;
	}
	void add(int age, std::string name)
	{
		Node* nd = new Node;
		(*nd).age = age;
		(*nd).name = name;
		(*nd).next = NULL; 

		if (head == NULL)
		{
			head = nd;
			size++;
		}
		else
		{
			Node* current = head;
			while ((*current).next != NULL)
			{
				current = (*current).next;
			}
			(*current).next = nd;
			size++;
		}
	}

	void delete_elem(int n)
	{
		Node* temp = head, * prev = NULL;

		int i = 0;
		while (temp && i < n)
		{
			i++;
			prev = temp;
			temp = (*temp).next;
		}
		if (!temp)
		{
			std::cout << "Элемент не найдет: " << n << std::endl;
			return;
		}
		if (head == temp)
		{
			head = (*temp).next;
		}
		else
		{
			if (prev)
			{
				(*prev).next = (*temp).next;
			}
		}
		std::cout << "Удаляемый элемент: " << (*temp).name << std::endl;
		size--;
		delete(temp);
	}
	
	void printList()
	{
		Node* current = head;
		while (current != NULL)
		{
			std::cout << "name: " << (*current).name << ", age: " << (*current).age << std::endl;
			current = (*current).next;
		}
		std::cout << "size: " << size << std::endl;
	}
};

class Invate :public List
{
public:
	void inv()
	{
		List ml;
		ml.add(23, "Blue");
		ml.add(25, "Red");
		ml.add(40, "Purple");
		ml.add(35, "Green");
		ml.add(50, "White");
		ml.printList();
		ml.delete_elem(1);
		ml.printList();
		ml.delete_elem(100);
	}
	
};



int main()
{
	setlocale(LC_CTYPE, "Russian");
	Invate invt;
	invt.inv();
}

