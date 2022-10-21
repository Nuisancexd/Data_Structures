#include <iostream>

class Que
{
private:
	int max_size;
	unsigned int* que_array;
	int upper;
	int lower;
	int n_items;
public:
	Que(int s) : upper(0), lower(-1), n_items(0), max_size(s)
	{
		que_array = new unsigned int[max_size];
	}

	void insert(unsigned int j)
	{
		if (lower == max_size - 1)
		{
			lower = -1;
		}
		que_array[++lower] = j;
		n_items += 1;
	}
	unsigned int remove()
	{
		unsigned int temp = que_array[upper++];
		if (upper == max_size)
		{
			upper = 0;
		}
		n_items -= 1;
		return temp;
	}
	unsigned int peek_upper()
	{
		return que_array[upper];
	}
	bool is_empty()
	{
		return n_items == 0;
	}
	unsigned int size()
	{
		return max_size;
	}
};

int main()
{
	Que qq(10);
	qq.insert(10);
	qq.insert(20);
	qq.insert(30);
	qq.insert(40);

	qq.remove();
	qq.remove();
	qq.remove();

	qq.insert(50);
	qq.insert(60);
	qq.insert(70);

	std::cout << "size: " << qq.size() << std::endl;
	std::cout << "upper: " << qq.peek_upper() << std::endl;

	while (!qq.is_empty())
	{
		unsigned int n = qq.remove();
		std::cout << n << " ";
	}

	return 0;
}
