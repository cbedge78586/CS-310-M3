// Charles Edge
// CS310-T301
// M3: Assignment

#include <iostream>
#include <iomanip>
using namespace std;

// Constant numbers for royalties as specified by instructions
const double FIXED_DELIVERY_PAYMENT = 5000.00;
const double FIXED_PUBLICATION_PAYMENT = 20000.00;
const double ROYALTY_RATE_OPTION2 = 0.125;
const double ROYALTY_RATE_OPTION3_FIRST = 0.10;
const double ROYALTY_RATE_OPTION3_SECOND = 0.14;
const int OPTION3_THRESHOLD = 4000;

int main() {
    double netPrice;
    int copiesSold;

    // Prompt user for input
    cout << "Enter the net price of each copy: $";
    cin >> netPrice;
    cout << "Enter the estimated number of copies to be sold: ";
    cin >> copiesSold;

    // Option 1: Fixed payments
    double royaltyOption1 = FIXED_DELIVERY_PAYMENT + FIXED_PUBLICATION_PAYMENT;

    // Option 2: Percentage of net price per copy
    double royaltyOption2 = ROYALTY_RATE_OPTION2 * netPrice * copiesSold;

    // Option 3: Tiered royalty rates
    double royaltyOption3;
    if (copiesSold <= OPTION3_THRESHOLD) {
        royaltyOption3 = ROYALTY_RATE_OPTION3_FIRST * netPrice * copiesSold;
    }
    else {
        royaltyOption3 = ROYALTY_RATE_OPTION3_FIRST * netPrice * OPTION3_THRESHOLD +
            ROYALTY_RATE_OPTION3_SECOND * netPrice * (copiesSold - OPTION3_THRESHOLD);
    }

    // Output results to screen
    cout << fixed << setprecision(2);
    cout << "\nEstimated Royalties:\n";
    cout << "Option 1 Fixed Payments: $" << royaltyOption1 << endl;
    cout << "Option 2 Percentage of Sales: $" << royaltyOption2 << endl;
    cout << "Option 3 Tiered Royalty Rates: $" << royaltyOption3 << endl;

    // This will determine which option is the best option of the 3
    double bestRoyalty = max(royaltyOption1, max(royaltyOption2, royaltyOption3));
    string bestOption;

    if (bestRoyalty == royaltyOption1) {
        bestOption = "Option 1 Fixed Payments.";
    }
    else if (bestRoyalty == royaltyOption2) {
        bestOption = "Option 2 Percentage of Sales.";
    }
    else {
        bestOption = "Option 3 Tiered Royalty Rates.";
    }

    // Outputs the best option to screen
    cout << "\nThe best option based on the data entered is: " << bestOption << endl;

    return 0;
}
