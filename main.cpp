#include "DropTable.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void)
{
	DropTable drops;

	drops.insertRarity("common", Ratio(1, 1));
	drops.insertRarity("uncommon", Ratio(1, 10));
	drops.insertRarity("magic", Ratio(1, 100));
	drops.insertRarity("rare", Ratio(1, 1000));
	drops.insertRarity("legendary", Ratio(1, 10000));

	std::srand(std::time(0));
	for (int i = 0; i < 10; i++)
	{
		cout << "Drop[" << i << "] = " << drops[std::rand()] << " rarity." << endl;
	}


	return 0;
}
