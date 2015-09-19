
//**************************************************************
// This program will calculate the total charge, including tax, 
// for a purchase of $95.
//**************************************************************

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
 
int main()  
{ 
    const float STATE_SALES_TAX = .04;
    const float COUNTY_SALES_TAX = .02;
    float stateTaxCharge;
    float countyTaxCharge;
    float totalCharge;
    
    float purchaseAmount = 95;
    
    stateTaxCharge = purchaseAmount * STATE_SALES_TAX;
    countyTaxCharge = purchaseAmount * COUNTY_SALES_TAX;
    totalCharge = purchaseAmount + countyTaxCharge + stateTaxCharge;
    
    cout << "The total charge for a $" << purchaseAmount << " purchase is $" 
    << showpoint << totalCharge;

    return 0;
}  
  