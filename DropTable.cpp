#include "DropTable.h"

DropTable::DropTable(void)
{
	// empty
}

DropTable::~DropTable(void)
{
	// empty
}

void DropTable::insertRarity(std::string name, const Ratio& rates)
{
	rarities.push_front({name, rates});
	Ratio maxRatio(1, 1);
	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		if (rarity.second.getDenominator() > maxRatio.getDenominator())
		{
			maxRatio.setDenominator(rarity.second.getDenominator());
		}
	}

	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		rarity.second.normalizeOn(maxRatio);
	}
}

#include <iostream>
using namespace std;

std::string DropTable::operator[](std::size_t randomValue)
{
	std::string ret = "UNKNOWN";
	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		randomValue %= rarity.second.getDenominator();
		cout << "[" << rarity.first << "] -> " << rarity.second.getNumerator() << "/" << rarity.second.getDenominator() << ", given value=" << randomValue << endl;
		if (rarity.second.contains(randomValue))
		{
			rarity.second.resetNumerator();
			ret = rarity.first;
		}
		rarity.second++;
		randomValue -= rarity.second.getNumerator();

	}
	return ret;
}
