#include "DropTable.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void)
{
	DropTable drops;

	drops.insertRarity("common",                         Ratio(1, 1));
	drops.insertRarity("\033[1muncommon\033[0m",         Ratio(1, 10));
	drops.insertRarity("\033[38;5;25mmagic\033[0m",      Ratio(1, 100));
	drops.insertRarity("\033[38;5;2mrare\033[0m",        Ratio(1, 10000));
	drops.insertRarity("\033[38;5;202mlegendary\033[0m", Ratio(1, 10000000));

	std::srand(std::time(0));
	for (int i = 0; i < 10000; i++)
	{
		cout << "Drop[" << i << "] = " << drops[std::rand()] << " quality." << endl;
	}


	return 0;
}
