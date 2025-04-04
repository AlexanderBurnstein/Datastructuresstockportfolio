// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "portfolio.h"

StockPortfolio::StockPortfolio()
{
    // Default constructor set to empty portfolio
}

void StockPortfolio::addStock(const Stock& inStock)
{
    // Can change to getSymbol if I want it to print the full name of the stock, use getName if I want just the stock symbol
	mStocks[inStock.getSymbol()] = inStock;
}

Money StockPortfolio::getTotalValue() const
{   
	Money totalValue;
    // Range based for loop to loop through each stock in our portfolio. mStocks is a map in .h
	for (const auto& [stockSymbol, stock]: mStocks)
	{
        // Multiplies current price of stock by the number of shares
		totalValue += stock.getCurrPrice() * stock.getNumShares();
	}
	return totalValue;
}

Money StockPortfolio::getOrigValue() const
{
	Money totalValue;
    // Range based for loop to loop through each stock in our portfolio. mStocks is a map in .h
	for (const auto& [stockSymbol, stock]: mStocks)
	{
        // Multiplies purchase price of stock by the number of shares
		totalValue += stock.getPurPrice() * stock.getNumShares();
	}
	return totalValue;
}

Money StockPortfolio::getProfit() const
{
    Money profit;
    // Range based for loop to loop through each stock in our portfolio. mStocks is a map in .h
    for (const auto& [stockSymbol, stock] : mStocks)
    {
        // Subtracts current price from purchase price and then multiplies by share number for the profit
        Money stockProfit = (stock.getCurrPrice() - stock.getPurPrice()) * stock.getNumShares();
        profit += stockProfit;
    }
    return profit;
}

std::vector<std::string> StockPortfolio::getAlphaList()
{
    // Vector to store the stock symbols
    std::vector<std::string> alphaList;
    // Go through the stocks map and store the stock symbols in the vector
    for (const auto& [stockSymbol, stock] : mStocks)
    {
        alphaList.push_back(stockSymbol);
    }

    // Selection sort by stockSymbol (alphabetically)
    for(int i = 0; i < alphaList.size() - 1; i++)
    {
        // Smallest stock symbol is set to i
        int minIndex = i;
        // Loop to find smallest stock symbol
        for(int j = i + 1; j < alphaList.size(); j++)
        {
            // Compare the strings
            if(alphaList[j] < alphaList[minIndex])
            {
                // Change index
                minIndex = j;
            }
        }
        // Swaps the smallest stock symbol with the index position
        if(minIndex != i)
        {
            std::string swapSymbol = alphaList[i];
            alphaList[i] = alphaList[minIndex];
            alphaList[minIndex] = swapSymbol;
        }
    }
    return alphaList;
}

std::vector<std::string> StockPortfolio::getValueList()
{
    std::vector<std::string> valueList;
    // Range based for loop to loop through each stock in our portfolio. mStocks is a map in .h
    for (const auto& [stockSymbol, stock] : mStocks)
    {
        valueList.push_back(stockSymbol);
    }
    // Selection sort by value (descending)
    for(int i = 0; i < valueList.size() - 1; i++)
    {
        int maxIndex = i;
        for(int j = i + 1; j < valueList.size(); j++)
        {
            // Gets the value of the stocks at index j and maxIndex
            Money currentValue = mStocks[valueList[j]].getCurrPrice() * mStocks[valueList[j]].getNumShares();
            Money maxValue = mStocks[valueList[maxIndex]].getCurrPrice() * mStocks[valueList[maxIndex]].getNumShares();

            // If the current stock is higher then update max index
            if(currentValue > maxValue)
            {
                maxIndex = j;
            }
        }
        // Swaps stocks based on value
        if(maxIndex != i)
        {
            std::string swapSymbol = valueList[i];
            valueList[i] = valueList[maxIndex];
            valueList[maxIndex] = swapSymbol;
        }
    }
    return valueList;
}

std::vector<std::string> StockPortfolio::getDiffList()
{
    std::vector<std::string> diffList;
    // Range based for loop to loop through each stock in our portfolio. mStocks is a map in .h
    for (const auto& [stockSymbol, stock] : mStocks)
    {
        diffList.push_back(stockSymbol);
    }

    // Selection sort by difference (descending)
    for(int i = 0; i < diffList.size() - 1; i++)
    {
        int maxIndex = i;
        for(int j = i + 1; j < diffList.size(); j++)
        {
            // Gets the difference between current price and purchase price
            Money currentDiff = mStocks[diffList[j]].getCurrPrice() - mStocks[diffList[j]].getPurPrice();
            Money maxDiff = mStocks[diffList[maxIndex]].getCurrPrice() - mStocks[diffList[maxIndex]].getPurPrice();
            
            // If current stock diff is greater then update the index
            if(currentDiff > maxDiff)
            {
                maxIndex = j;
            }
        }
        // Swaps symbols based on price difference
        if(maxIndex != i)
        {
            std::string swapSymbol = diffList[i];
            diffList[i] = diffList[maxIndex];
            diffList[maxIndex] = swapSymbol;
        }
    }
    return diffList;
}

bool StockPortfolio::containsStock(const std::string& inSymbol) const
{
    // Checks if the stock symbol exists
    return mStocks.find(inSymbol) != mStocks.end();
}

Stock& StockPortfolio::operator[](const std::string& inSymbol)
{
    // Get stock symbol 
    return mStocks[inSymbol];
}