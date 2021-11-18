#pragma once

#include <iostream>
#include <string>

using namespace std;

class Hash
{
public:
	Hash();
	~Hash();

	int				NumItemsInIndex(int index);
	bool			AddItem(string Key, string Data);
	string			FindItem(string Key);
	bool			RemoveItem(string Key);
	bool			PrintTable();

private:
	static const int		m_TableSize = 100;
	uint32_t		HashFunction(string key);

	struct Item
	{
		string Key;
		string Data;

		Item* next;
	};

	Item*					m_HashTable[m_TableSize];

};


