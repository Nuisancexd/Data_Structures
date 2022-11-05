#include <iostream>


template<typename K, typename V>
class HashNode 
{
public:
	V value;
	K key;
	HashNode(K key, V value) // конструктор для hash node
	{
		this->value = value;
		this->key = key;
	}
};

template<typename K, typename V>
class HashMap
{
public:
	HashNode<K, V>** arr; // массив хэш элементов и ссылка на связку
	int capasity;
	int size;
	HashNode<K, V>* del; // массив для удаления ключа
public:
	HashMap()
	{
		capasity = 20;
		size = 0;
		arr = new HashNode<K, V>*[capasity];
		for (int i = 0; i < capasity; i++)
		{
			arr[i] = NULL;
		}
		del = new HashNode<K, V>(-1, "");
		//del = new HashNode<K, V>(-1, -1);
	}
	int hash_code(K key) // хеш функция для поиска индекса для ключа
	{
		return key % capasity;
	}
	// insert key value pair
	void insert_node(K key, V value)
	{
		HashNode<K, V>* temp = new HashNode<K, V>(key, value);
		int hash_index = hash_code(key); // индекс данного ключа
		//std::cout << "hash index: " << hash_index << std::endl;

		// Находим свободное место
		while (arr[hash_index] != NULL && arr[hash_index]->key != key && arr[hash_index]->key != -1)
		{
			hash_index++;
			hash_index %= capasity;
		}
		// если нашли свободно место, вставляем данные
		if (arr[hash_index] == NULL || arr[hash_index]->key == -1)
		{
			size++;
			arr[hash_index] = temp;
		}
	}
	V delete_node(int key)
	{
		int hash_index = hash_code(key);

		while (arr[hash_index] != NULL)
		{
			if (arr[hash_index]->key = key)
			{
				HashNode<K, V>* temp = arr[hash_index];
				arr[hash_index] = del;
				size--;
				return temp->value;
			}
			hash_index++;
			hash_index %= capasity;
		}
		return NULL;
	}

	bool get(int key)
	{
		int hash_index = hash_code(key);

		int counter = 0;
		while (arr[hash_index] != NULL)
		{
			//избежать бесконечного цикла
			if (counter++ > capasity)
			{
				return NULL;
			}
			if (arr[hash_index]->key == key)
			{
				return true;//arr[hash_index]->value;
			}
			hash_index++;
			hash_index %= capasity;
		}
		return false;
	}

	int size_of_map() const
	{
		return size;
	}
	bool is_empty() const
	{
		return size == 0;
	}
	void display()
	{
		for (int i = 0; i < capasity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
			{
				std::cout << "key: " << arr[i]->key << " value: " << arr[i]->value << std::endl;
			}
		}
	}
};



int main()
{
	HashMap<int, std::string>* hp = new HashMap<int, std::string>;
	hp->insert_node(1, "Clown Sad");
	hp->insert_node(2, "Clown Rage");
	hp->display();

	std::cout << hp->size_of_map() << std::endl;
	std::cout << hp->delete_node(2) << std::endl;
	std::cout << hp->size_of_map() << std::endl;
	hp->display();

	std::cout << std::endl;

	hp->insert_node(2, "Clown Ghoul");
	hp->insert_node(3, "Clown Zitraks");
	hp->insert_node(4, "Clown Mode");
	std::cout << hp->get(2) << std::endl;
	hp->display();
	std::cout << std::endl;

	hp->insert_node(30, "Clown Heh");
	hp->display();

	/*HashMap<int, int>* hp = new HashMap<int, int>;
	hp->insert_node(1, 1);
	hp->insert_node(2, 2);
	hp->insert_node(2, 3);
	hp->display();
		
	std::cout << hp->size_of_map() << std::endl;
	std::cout << hp->delete_node(2) << std::endl;
	std::cout << hp->size_of_map() << std::endl;
	std::cout << hp->is_empty() << std::endl;
	std::cout << hp->get(2) << std::endl;
	hp->display();
	std::cout << std::endl;
	hp->insert_node(3, 1);
	hp->insert_node(1, 2);
	hp->insert_node(2, 5);
	hp->insert_node(5, 7);
	hp->display();
	*/
	return 0;
}