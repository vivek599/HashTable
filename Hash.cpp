#include "Hash.h"

Hash::Hash()
{
	for (int i = 0; i < m_TableSize; i++)
	{
		m_HashTable[i]			= new Item();
		m_HashTable[i]->Key		= "";
		m_HashTable[i]->Data	= nullptr;
		m_HashTable[i]->next	= nullptr;
	}
}

Hash::~Hash()
{
	for (int i = 0; i < m_TableSize; i++)
	{ 
		Item* deleted = m_HashTable[i];
		
		while (deleted->next)
		{
			Item* b = deleted;
			deleted = deleted->next;
			delete b;
		}

		delete deleted;
	}
}

uint32_t Hash::HashFunction(string key)
{
	uint32_t h = 0;
	uint32_t index = 0;

	for (int i = 0; i < (int)key.size(); i++)
	{
		char c = toupper(key[i]);
		h = ((h << 5) + h) ^ c;
	}

	index = h % m_TableSize;

	return index;
}

int Hash::NumItemsInIndex(int index)
{
	int count = 0;

	Item* item = m_HashTable[index];

	if (item->Key == "")
	{
		return count;
	}
	else
	{
		count++;

		while (item->next)
		{
			count++;
			item = item->next;
		}
	}

	return count;
}

bool Hash::AddItem(string _Key, void* _Data)
{
	int index = HashFunction(_Key);
	Item* item = m_HashTable[index];
	
	if (item->Key == "" )
	{
		item->Key = _Key;
		item->Data = _Data;
	}
	else
	{
		Item* n = new Item();
		n->Key = _Key;
		n->Data = _Data;
		n->next = nullptr;
		while (item->next)
		{
			item = item->next;
		}

		item->next = n;
	}

	return true;
}

void* Hash::FindItem(string Key)
{
	int index = HashFunction(Key);

	Item* item = m_HashTable[index];

	while (item)
	{
		if (item->Key == Key)
		{
			return item->Data;
		}
		item = item->next;
	}

	return nullptr;
}

bool Hash::RemoveItem(string Key)
{
	int index = HashFunction(Key);
	Item* item = m_HashTable[index];

	Item* next;
	Item* current;

	if (item->Key == "" && item->Data == "" )
	{
		//not found
		return false;
	}
	else if( item->Key == Key && item->next == nullptr )
	{
		item->Key	= "";
		item->Data	= nullptr;
	}
	else if (item->Key == Key)
	{
		m_HashTable[index] = item->next;
		delete item;
	}
	else
	{
		next	= item->next;
		current = item;

		while (next && current->Key != Key)
		{
			current = next;
			next = next->next;
		}

		if (!next)
		{
			//not found
			return false;
		}
		else
		{
			Item* deleted = next;
			next = next->next;
			current->next = next;
			delete deleted;
		}
	}

	return true;
}


