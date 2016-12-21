#include "Ratio.h"

Ratio::Ratio(std::size_t num, std::size_t denom)
{
	mOriginalNumerator = num;
	setNumerator(num);
	setDenominator(denom);
}
Ratio::Ratio(const Ratio& src)
{
	*this = src;
}

Ratio::~Ratio(void)
{
	// empty
}

std::size_t Ratio::getNumerator(void) const
{
	return mNumerator;
}

std::size_t Ratio::getDenominator(void) const
{
	return mDenominator;
}

void Ratio::setDenominator(std::size_t denom)
{
	mDenominator = denom;
}

void Ratio::setNumerator(std::size_t num)
{
	mNumerator = num;
}

Ratio& Ratio::operator++(void)
{
	return (*this)++;
}

Ratio& Ratio::operator++(int)
{
	mNumerator++;
	return *this;
}

Ratio& Ratio::operator=(const Ratio& src)
{
	if (this == &src)
	{
		return *this;
	}

	mDenominator = src.mDenominator;
	mNumerator = src.mNumerator;
	mOriginalNumerator = src.mOriginalNumerator;
	return *this;
}

bool Ratio::contains(std::size_t value) const
{
	return value <= mNumerator;
}

void Ratio::resetNumerator(void)
{
	mNumerator = mOriginalNumerator;
}

void Ratio::normalizeOn(const Ratio& other)
{
	if (mDenominator == other.mDenominator)
	{
		return;
	}
	mNumerator *= other.mDenominator;
	mOriginalNumerator  *= other.mDenominator;
	mDenominator *= other.mDenominator;
}

void Ratio::normalizeEach(Ratio& other)
{
	if (mDenominator == other.mDenominator)
	{
		return;
	}
	std::size_t tempDenom = mDenominator;
	mNumerator *= other.mDenominator;
	mOriginalNumerator  *= other.mDenominator;
	mDenominator *= other.mDenominator;

	other.mNumerator *= tempDenom;
	other.mOriginalNumerator *= tempDenom;
	other.mDenominator *= tempDenom;
}

