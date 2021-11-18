

#include "Hash.h"


int main()
{
	Hash* h = new Hash();

	h->AddItem("paul", (void*)"punch");
	h->AddItem("paul", (void*)"phyonix");
	h->AddItem("jin", (void*)"kick");
	h->AddItem("eddy", (void*)"twist");
	h->AddItem("eddy", (void*)"Leg");
	h->AddItem("eddy", (void*)"split");
	h->AddItem("xiaou", (void*)"arm");

	h->PrintTable<char>();

	h->RemoveItem("eddy");
	h->RemoveItem("eddy");
	h->RemoveItem("eddy");

	h->PrintTable<char>();

	delete h;

	system("pause");
	return 0;
}
