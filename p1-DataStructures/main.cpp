// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include <iostream>
#include "money.h"
#include <string>
#include <vector>
#include <sstream>
#include "driver.h"
#include "portfolio.h"
#include "strlib.h"

int main()
{
    // Testing Driver
    StockPortfolio portfolio;

    // Call processFile with the path to your test file
    bool fileOpenTest = processFile(portfolio, "input/test01.txt");

    if (fileOpenTest)
    {   
        // You can add additional checks or print out the contents of the portfolio to verify
        // For example, print the stock symbols or other details:
        for (const auto& stockSymbol : portfolio.getAlphaList())
        {
            std::cout << stockSymbol << std::endl;
        }
    }
    /* // Further test Portfolio Class
    StockPortfolio portfolio;

    // Test Stock 1
    Money brkAPurchasePrice(1307.00);
    Stock brkA("BRK.A", "Berkshire Hathaway Inc. Cl A", brkAPurchasePrice, 11);
    brkA.setCurrentPrice(Money(1700.00));
    portfolio.addStock(brkA);

    // Test Stock 2
    Money applPurchasePrice(0.11);
    Stock appl("APPL", "Apple Inc.", applPurchasePrice, 10000);
    appl.setCurrentPrice(Money(0.15));
    portfolio.addStock(appl);

    // Test Stock 3
    Money mdlzPurchasePrice(31.07);
    Stock mdlz("MDLZ", "Mondelez International Inc. Cl A", mdlzPurchasePrice, 30);
    mdlz.setCurrentPrice(Money(35.00));
    portfolio.addStock(mdlz);

    // Cout testing stock values and profit
    std::cout << "Total Stocks Value: " << portfolio.getTotalValue() << std::endl;
    std::cout << "Original Stocks Value: " << portfolio.getOrigValue() << std::endl;
    std::cout << "Stock Profit: " << portfolio.getProfit() << std::endl;

    // Selection sort alphabetically
    std::vector<std::string> alphaList = portfolio.getAlphaList();
    std::cout << "Stocks Alphabetically Sorted: ";
    for (const auto& stockSymbol : alphaList)
    {
        std::cout << stockSymbol << " ";
    }
    std::cout << std::endl;

    // Selection sort stock values
    std::vector<std::string> valueList = portfolio.getValueList();
    std::cout << "Stocks Sorted by Value: ";
    for (const auto& stockSymbol : valueList)
    {
        std::cout << stockSymbol << " ";
    }
    std::cout << std::endl;

    // Selection sort by difference
    std::vector<std::string> diffList = portfolio.getDiffList();
    std::cout << "Stocks Sorted by Difference: ";
    for (const auto& stockSymbol : diffList)
    {
        std::cout << stockSymbol << " ";
    }
    std::cout << std::endl; */

    /* // Test to see if portfolio class is working
    Stock brk("Berkshire Hathaway", "BRK.A", Money(1307, 0), 10);
    brk.setCurrentPrice(Money(1700, 0));
    StockPortfolio testStock;
    testStock.addStock(brk);
    std::cout << "Total Stocks Value: " << testStock.getTotalValue() << std::endl;
    std::cout << "Original Stocks Value: " << testStock.getOrigValue() << std::endl;
    std::cout << "Stock Profit: " << testStock.getProfit() << std::endl; */

    /* // Test to see if stock class is working
    // Print a default stock from default constructor
    Stock defaultStock;
    std::cout << defaultStock << std::endl;
    // Testing out disney stock test as per the gittest
    Money testStockPrice(10010);
    Stock disneyStock("Disney", "DIS", testStockPrice, 2.01);
    std::cout << disneyStock; */

    
	/* // Test function in main to see if strlib is working properly
	std::vector<std::string> testVector = strSplit("Test1|Test2|Test3|Test4|Test5", '|');
	for (int i = 0; i < testVector.size(); i++)
    {
    std::cout << testVector[i] << std::endl;
    } */

	/* // Testing money class from hw2
    Money m1, m2;
	// Testing input
	std::cout << "Enter m1: ";
    std::cin >> m1;

    std::cout << "Enter m2: ";
    std::cin >> m2; */

	// Testing output to see if money is displayed correctly
	/* Money m1(101);
	Money m2(190); */
	/* Money m3(2000);
	Money m4;

	// Reg Test
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;

	// Test addition
    Money sum = m1 + m2;
    std::cout << "m1 + m2 = " << sum << std::endl;
    
    // Test subtraction
    Money diff = m2 - m1;
    std::cout << "m2 - m1 = " << diff << std::endl;
    
    // Test multiplication
    Money product = m2 * -0.9;
    std::cout << "m2 * -0.9 = " << product << std::endl;
    
    // Test division
    Money division = m2 / -0.9;
    std::cout << "m2 / -0.9 = " << division << std::endl;
    
    // Test +=
    m2 += m1;
    std::cout << "m2 += m1 = " << m2 << std::endl;
    
    // Test -=
    m2 -= m1;
    std::cout << "m2 -= m1 = " << m2 << std::endl;
    
    // Test *=
    m2 *= -0.90;
    std::cout << "m2 *= -0.90 = " << m2 << std::endl;
    
    // Test /=
    m2 /= 2;
    std::cout << "m2 /= 2 = " << m2 << std::endl;
	*/
	return 0;
}