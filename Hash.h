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
	bool			AddItem(string Key, void* Data);
	void* 			FindItem(string Key);
	bool			RemoveItem(string Key);
	template<typename T>
	bool PrintTable()
	{
		cout << "---------------------" << endl;
		for (int i = 0; i < m_TableSize; i++)
		{
			Item* item = m_HashTable[i];

			int items = NumItemsInIndex(i);

			if (item->Key != "")
			{
				cout << "Index: " << i << " Count: " << items << " ---> " << item->Key << " ";
				for (int i = 0; i < items; i++)
				{
					cout << (static_cast<T*>(item->Data)) << ", ";
					item = item->next;
				}
				cout << endl;
			}
		}

		return true;
	}

private:
	static const int		m_TableSize = 100;
	uint32_t		HashFunction(string key);

	struct Item
	{
		string Key;
		void* Data;

		Item* next;
		Item()
		{
			Key = "";
			Data = nullptr;
			next = nullptr;
		}
	};

	Item*					m_HashTable[m_TableSize];

};


