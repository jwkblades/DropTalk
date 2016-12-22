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
	std::size_t denom = 1;
	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		if (rarity.second.getDenominator() > denom)
		{
			denom = rarity.second.getDenominator();
		}
	}

	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		rarity.second.normalizeOn(denom);
	}
}

std::string DropTable::operator[](std::size_t randomValue)
{
	std::string ret = "\033[1m\033[38;5;9mUNKNOWN\033[0m";
	randomValue = (double(randomValue) / double(RAND_MAX)) * double(rarities.front().second.getDenominator());
	bool found = false;
	for (std::pair<std::string, Ratio>& rarity : rarities)
	{
		if (!found && rarity.second.contains(randomValue))
		{
			rarity.second.resetNumerator();
			ret = rarity.first;
			found = true;
		}
		randomValue -= rarity.second.getNumerator();
		rarity.second++;
	}
	return ret;
}
