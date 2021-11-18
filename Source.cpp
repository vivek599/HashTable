

#include "Hash.h"


int main()
{
	Hash* h = new Hash();

	h->AddItem("paul", "punch");
	h->AddItem("paul", "phyonix");
	h->AddItem("jin", "kick");
	h->AddItem("eddy", "twist");
	h->AddItem("eddy", "Leg");
	h->AddItem("eddy", "split");
	h->AddItem("xiaou", "arm");

	h->PrintTable();

	h->RemoveItem("eddy");
	h->RemoveItem("eddy");
	h->RemoveItem("eddy");

	h->PrintTable();

	delete h;

	system("pause");
	return 0;
}
