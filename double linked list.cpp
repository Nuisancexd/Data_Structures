#include <iostream>

template<typename D>
class Node
{
public:
	D data;
	Node<D>* next;
	Node<D>* prev;
	Node(D data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

template<typename D>
class DoubleLinkedList
{
private:
	Node<D>* head;
	Node<D>* tail;
	int size;
public:
	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~DoubleLinkedList() { }

	void insert_front(D data)
	{
		Node<D>* temp = new Node<D>(data);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		size++;
	}
	void insert_back(D data)
	{
		Node<D>* temp = new Node<D>(data);
		if (tail == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}
	D delete_front()
	{
		if (!is_empty())
		{
			Node<D>* temp = head;
			D del_data = temp->data;
			if (head == tail)
			{
				tail = NULL;
				head = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}
			delete temp;
			size--;
			return del_data;
			
		}
		return NULL;
	}
	D delete_back()
	{
		if (!is_empty())
		{
			Node<D>* temp = tail;
			D del_data = temp->data;
			if (head == tail)
			{
				tail = NULL;
				head = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;

			}
			delete temp;
			size--;
			return del_data;
		}
		return NULL;
	}
	D search(D data)
	{
		if (!is_empty())
		{
			Node<D>* temp = head;
			while (temp)
			{
				if (temp->data == data)
				{
					return data;
				}
				temp = temp->next;
			}
		}
		else
		{
			return NULL;
		}
	}
	bool is_empty()
	{
		return size == 0;
	}
	void display()
	{
		Node<D>* temp = head;

		for (int i = 0; i < size; i++)
		{
			std::cout << "data: " << temp->data << std::endl;
			temp = temp->next;
		}
	}
	int lenght()
	{
		return size;
	}
};


int main()
{
	DoubleLinkedList<std::string>* dll = new DoubleLinkedList<std::string>();

	dll->insert_front("Clown sad");
	dll->insert_front("Clown happ");
	dll->insert_back("Tasai core");
	dll->insert_back("Tasai mix");

	dll->display();
	std::cout << std::endl << "size: " << dll->lenght() << std::endl;

	dll->delete_front();
	dll->delete_back();
	dll->display();
	std::cout << std::endl << "size: " << dll->lenght() << std::endl;

	std::cout << dll->search("Clown sad");
	return 0;
}