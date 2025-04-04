// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "stock.h"

Stock::Stock()
{
	mName = "";
	mSymbol = "";
	mPurchasePrice = Money();
	mCurrentPrice = Money();
	mNumShares = 0.0;
}

Stock::Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares)
{
	mName = inName;
	mSymbol = inSymbol;
	mPurchasePrice = inPurPrice;
	mCurrentPrice = inPurPrice;
	mNumShares = inNumShares;
}

Money Stock::getCurrPrice() const
{
	return mCurrentPrice;
}

Money Stock::getPurPrice() const
{
	return mPurchasePrice;
}

Money Stock::getChange() const
{
	return mCurrentPrice - mPurchasePrice;
}

std::string Stock::getSymbol() const
{
	return mSymbol;
}

std::string Stock::getName() const
{
	return mName;
}

double Stock::getNumShares() const
{
	return mNumShares;
}

void Stock::setCurrentPrice(const Money& inCurrPrice)
{
	mCurrentPrice = inCurrPrice;
}

// Stream operators
std::ostream& operator<<(std::ostream& out, const Stock& stock)
{
	out << stock.mSymbol << " : " << stock.mNumShares << " @ " << stock.mCurrentPrice;
	return out;
}