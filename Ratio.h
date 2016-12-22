#ifndef __RATIO_H
#define __RATIO_H

#include <cstdlib>

class Ratio
{
public:
	Ratio(std::size_t num, std::size_t denom);
	Ratio(const Ratio& src);
	~Ratio(void);

	std::size_t getNumerator(void) const;
	std::size_t getDenominator(void) const;

	void setNumerator(std::size_t num);
	void setDenominator(std::size_t denom);

	Ratio& operator++(void);
	Ratio& operator++(int);

	Ratio& operator=(const Ratio& src);

	bool contains(std::size_t value) const;

	void resetNumerator(void);

	void normalizeOn(std::size_t newDenom);

private:
	std::size_t mOriginalNumerator;
	std::size_t mIncrement;
	std::size_t mNumerator;
	std::size_t mDenominator;
};

#endif
