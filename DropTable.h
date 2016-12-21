#ifndef __DROP_TABLE_H
#define __DROP_TABLE_H

#include "Ratio.h"

#include <string>
#include <utility>
#include <list>

class DropTable
{
public:
	DropTable(void);
	~DropTable(void);

	void insertRarity(std::string name, const Ratio& rates);

	std::string operator[](std::size_t randomValue);

private:
	std::list<std::pair<std::string, Ratio>> rarities;
};

#endif
