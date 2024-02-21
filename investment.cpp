#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

/*
 * * Author: De'sean Newcomb
 * * Description: This program helps users decide how to invest their money
 *      among different investment options (US Treasury I bonds, high-yield
 *              savings accounts, and index funds),
 * * based on user input of investment amount and APY (annual percentage yield)
 *       of each investment option.
 * */

// Prompt the user to enter the total amount of money they have to invest
double getTotalInvestmentAmount() {
        double amount;
        cout << "Enter the total amount of money that you have to invest (in"
                        "dollars, as a whole number): ";
        cin >> amount;
        return amount;
}

// Prompt the user to enter the APY and maximum balance of their high-yield
//      savings account
void getHYSAInfo(double& hysaAPY, double& hysaMax) {
        cout << "Enter the APY of your target HYSA (as a percent): ";
        cin >> hysaAPY;

        // If the user enters a negative value for APY, set it to the default
        //      value of 4%
        if (hysaAPY < 0) {
                cout << "Error: Negative values are not allowed for APY. Using"
                        "default value of 4%." << endl;
                hysaAPY = 4.0;
        }

        cout << "Enter the FDIC insurance maximum of your target HYSA (in"
                "dollars, as a whole number): ";
        cin >> hysaMax;

        // If the user enters a negative value for maximum balance, set it to
        //      the default value of $250,000
        if (hysaMax < 0) {
                cout << "Error: Negative values are not allowed for FDIC"
                        "insurance maximum. Using default value of $250,000." << endl;
                hysaMax = 250000.0;
        }
}

// Prompt the user to enter the APY of US Treasury I bonds
double getIBondAPY() {
        double apy;
        cout << "Enter the current APY of US Treasury I bonds (as a percent): ";
        cin >> apy;

         // If the user enters a negative value for APY, set it to the default
         //     value of 6%
        if (apy < 0) {
                cout << "Error: Negative values are not allowed for APY. Using"
                        "default value of 6%." << endl;
                apy = 6.0;
        }

        return apy;
}

// Prompt the user to enter the APY of their target index fund
double getIndexFundAPY() {
        double apy;
        cout << "Enter the APY of your target index fund (as a percent): ";
        cin >> apy;

        // If the user enters a negative value for APY, set it to the
        //      default value of 10%
        if (apy < 0) {
                cout << "Error: Negative values are not allowed for APY. Using"
                        "default value of 10%." << endl;
                apy = 10.0;
        }

        return apy;
}

// Calculate the amount to invest in each option based on user input
void calculateInvestmentAmounts(double totalInvestment, double hysaAPY, double hysaMax, double ibondAPY, double indexFundAPY) {
        double amountHYSA = totalInvestment;
        if (hysaMax < totalInvestment) {
                amountHYSA = hysaMax;
        }

        double remainingAmount = totalInvestment - amountHYSA;

        double amountIBond = remainingAmount;
        if (remainingAmount > 10000.0) {
            amountIBond = 10000.0;
        }

        remainingAmount -= amountIBond;

        // Print the recommended investment amounts
        double amountIndexFund = remainingAmount;
        cout << "You should invest $" << amountIBond << " into I bonds." << endl;
        cout << "You should invest $" << amountHYSA << " into your target HYSA."
                 << endl;
        cout << "You should invest $" << amountIndexFund << " into your target"
                "index fund." << endl;

        // Calculate and print the total profit from the investments
        double totalProfit = (amountHYSA * (hysaAPY / 100)) + (amountIBond *(ibondAPY / 100)) + (amountIndexFund * (indexFundAPY / 100));
        cout << "In total, these investments will earn you $" << totalProfit <<
                " over the next year." << endl;
}


int main() {
        double totalInvestment = getTotalInvestmentAmount();
        double hysaAPY, hysaMax;
        getHYSAInfo(hysaAPY, hysaMax);
        double ibondAPY = getIBondAPY();
        double indexFundAPY = getIndexFundAPY();
        calculateInvestmentAmounts(totalInvestment, hysaAPY, hysaMax, ibondAPY,
                        indexFundAPY);

        return 0;
}


