// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "driver.h"
#include "strlib.h"
#include "stock.h"
#include <fstream>
#include <iostream>

// Function to add a stock to the portfolio
bool buyStock(StockPortfolio& inPort, const std::string& inString)
{
	// Splits input string based on delimiter '|'
    std::vector<std::string> stockData = strSplit(inString, '|');
	// Checks for symbol, name, price, numshares if input isn't formatted correctly return false 
    if (stockData.size() != 4)
	{
    	return false;
	}
	// Goes through the vector and gets parts it needs at respective index
    std::string symbol = stockData[0];
    std::string name = stockData[1];
	// Converts string to double
    double purchasePrice = std::stod(stockData[2]);
	// Converts string to double
    double numShares = std::stod(stockData[3]);

	// Make a new stock object using the data we pulled from the vector
    Stock newStock(name, symbol, purchasePrice, numShares);
	// Adds stock to the portfolio
    inPort.addStock(newStock);

    return true;
}

// Function to update an existing stock's price
bool updateStock(StockPortfolio& inPort, const std::string& inString)
{
	// Splits input string based on delimiter '|'
    std::vector<std::string> stockData = strSplit(inString, '|');
	// Checks for correct input size (symbol and new price) if input isn't formatted correctly return false
    if (stockData.size() != 2)
	{
        return false;
	}
	// Goes through the vector and gets parts it needs at respective index
    std::string symbol = stockData[0];
	// Converts string to double
    double newPrice = std::stod(stockData[1]);
	// Handle situation where tests were adding stock that shouldnt exist
	if (inPort.containsStock(symbol) == true)
	{
		// Update the stock's price in portfolio using symbol
    	inPort[symbol].setCurrentPrice(Money(newPrice));
	}
	else
	{
		return false;
	}

    return true;
}

// Function to process a file and update the portfolio
bool processFile(StockPortfolio& inPort, const std::string& fileName)
{
	// Open File
    std::ifstream file(fileName);
	// Returns False if file can't be opened
    if (!file.is_open())
        return false;

    std::string line;
	// Use while loop to grab each line
    while (std::getline(file, line))
    {
		// Skips empty line
        if (line.empty())
		{
            continue;
		}
		// If the line starts with a '+' sign then it must be an update
        if (line[0] == '+')
        {
            // Remove '+' and call updateStock
            std::string updateLine = line.substr(1);
            updateStock(inPort, updateLine);
        }
        else
        {
            // Add a new stock
            buyStock(inPort, line);
        }
    }

	// Close file
    file.close();
    return true;
}