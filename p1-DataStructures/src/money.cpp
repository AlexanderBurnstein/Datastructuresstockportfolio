// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "money.h"

// Default Constructor starts cents at 0
Money::Money()
{
	mCents = 0;
}

Money::Money(double inDollars)
{
	// Changes dollars to cents
	mCents = inDollars * 100;
}

Money::Money(long long inDollars, long long inCents)
{
	// Changes dollars to cent and then adds the cents
	mCents = (inDollars * 100) + inCents;
}

Money::Money(long long inCents)
{
	// Cents if long long
	mCents = inCents;
}

Money::Money(int inCents)
{
	// Cents if int
	mCents = inCents;
}

long long Money::getCents()
{
	// Returns Cents
	return mCents;
}

Money& Money::operator+=(const Money& right)
{
	mCents += right.mCents;
	return *this;
}

Money& Money::operator-=(const Money& right)
{
	mCents -= right.mCents;
	return *this;
}

Money& Money::operator*=(double right)
{
	mCents = (long long)(mCents * right);
	return *this;
}

Money& Money::operator/=(double right)
{
	mCents = (long long)(mCents / right);
	return *this;
}

Money operator+(const Money& left, const Money& right)
{
	return Money(left.mCents + right.mCents);
}

Money operator-(const Money& left, const Money& right)
{
	return Money(left.mCents - right.mCents);
}

Money operator*(const Money& left, double right)
{
	return Money((long long)(left.mCents * right));
}

Money operator/(const Money& left, double right)
{
	return Money((long long)(left.mCents / right));
}

bool operator==(const Money& left, const Money& right)
{
	return left.mCents == right.mCents;
}

bool operator!=(const Money& left, const Money& right)
{
	return left.mCents != right.mCents;
}

bool operator<(const Money& left, const Money& right)
{
	return left.mCents < right.mCents;
}

bool operator>(const Money& left, const Money& right)
{
	return left.mCents > right.mCents;
}
bool operator<=(const Money& left, const Money& right)
{
	return left.mCents <= right.mCents;
}

bool operator>=(const Money& left, const Money& right)
{
	return left.mCents >= right.mCents;
}

std::ostream& operator<<(std::ostream& out, const Money& money)
{
	// Outputs money in correct formatting
	long long dollars = money.mCents / 100;
    long long cents = money.mCents % 100;
	// If money is positive, print normally
    if (money.mCents < 0)
	{
		// Negative dollars for negative numbers
        out << "$-" << -dollars;
		// Flips cents value positive
		cents = -cents;
    }
	// If money is negative add a - sign to output
    else
	{
        out << "$" << dollars;
    }
	// Outputs dot to separate the cents
	out << ".";
    // If cents are less than 10, pad with a leading zero
    if (cents < 10)
    {
        out << "0";
    }
    out << cents;
	return out;
}

std::istream& operator>>(std::istream& in, Money& money)
{
	// Takes input as a double
	double dollars;
    in >> dollars;
	// Swaps dollars to cents
    money.mCents = dollars * 100;
    return in;
}