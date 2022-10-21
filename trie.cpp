#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 26

typedef struct TrieNode TrieNode;

struct TrieNode
{
	char data;
	TrieNode* children[N];
	int is_leaf;
};

TrieNode* make_trinenode(char data) // Инициализация в памяти
{
	TrieNode* node = (TrieNode*) calloc(1, sizeof(TrieNode));

	for (int i = 0; i < N; i++)
	{
		(*node).children[i] = NULL;
	}
	(*node).is_leaf = 0;
	(*node).data = data;
	return node;
}

void free_trienode(TrieNode* node) // Освобождение указателя
{
	for (int i = 0; i < N; i++)
	{
		if ((*node).children[i] != NULL)
		{
			free_trienode((*node).children[i]);
		}
		else
		{
			continue;
		}
	}
	delete node;
}

TrieNode* insert_trie(TrieNode* root, char* word) // вставка слов
{
	TrieNode* temp = root;

	for (int i = 0; word[i] != '\0'; i++)
	{
		int idx = (int)word[i] - 'a';
		if ((*temp).children[idx] == NULL)
		{
			(*temp).children[idx] = make_trinenode(word[i]);
		}
		else { }
		temp = (*temp).children[idx];
	}
	(*temp).is_leaf = 1;
	return root;
}


int search_trie(TrieNode* root, char* word) // поиск заданного шаблона
{
	TrieNode* temp = root;

	for (int i = 0; word[i] != '\0'; i++)
	{
		int position = word[i] - 'a';
		if ((*temp).children[position] == NULL)
		{
			return 0;
		}
		temp = (*temp).children[position];
	}
	if (temp != NULL && (*temp).is_leaf == 1)
	{
		return 1;
	}
	return 0;
}



void print_trie(TrieNode* root)
{
	if (!root)
	{
		return;
	}
	TrieNode* temp = root;
	std::cout << (*temp).data << " -> ";

	for (int i = 0; i < N; i++)
	{
		print_trie((*temp).children[i]);
	}
}
void print_search(TrieNode* root, char* word)
{
	std::cout << "Search for " << word;
	if (search_trie(root, word) == 0)
	{
		std::cout << " Not found" << std::endl;
	}
	else
	{
		std::cout << " found" << std::endl;
	}
}

int main()
{
	TrieNode* root = make_trinenode('\0');
	char ct1[] = "clown";
	char ct2[] = "die";
	char ct3[] = "broke";
	char ct4[] = "heart";
	root = insert_trie(root, ct1);
	root = insert_trie(root, ct2);
	root = insert_trie(root, ct3);
	root = insert_trie(root, ct4);

	print_search(root, ct1);
	print_search(root, ct2);
	print_search(root, ct3);
	print_search(root, ct4);

	print_trie(root);

	std::cout << std::endl;

	free_trienode(root);

	//delete[] ct1;
//	delete[] dlt2;

	return 0;
}
