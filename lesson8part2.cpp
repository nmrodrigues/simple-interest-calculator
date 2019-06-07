// This program is designed to read in a future value,
// an annual interest rate, and anumber of years and will
// use those inputs to calculate the present value.
// Once the present value is calculated, the results will be displayed to the screen.
// This program uses 6 functions to achieve this goal.

#include <iostream>
#include <cmath> // used to the pow function
#include <iomanip> // used for setprecision
using namespace std;

// function prototypes
double readFutureValue();
double readAnnualInterestRate();
int readNumberOfYears();
double calculatePresentValue(double futureValue, double interestRate, int numberYears);
void displayResults(double presentValue, double futureValue, double interestRate, int numberYears);
int main() {
    // assigns what is returned from the function readFutureValue to futureValue
    double futureValue = readFutureValue();
    // data validation to ensure that the futureValue is greater than 0
    while(futureValue <= 0.0){
        cout << "The future value must be greater than zero" << endl;
        futureValue = readFutureValue();
    }

    // assigns what is returned from the function rreadAnnualInterestRate() to percentInterestRate
    double percentInterestRate = readAnnualInterestRate();
    // data validation to ensure that the percentInterestRate is greater than 0
    while (percentInterestRate <=  0.0){
        cout << "The annual interest rate must be greater than zero" << endl;
        percentInterestRate = readAnnualInterestRate();
    }

    // assigns what is returned from the function readNumberOfYears() to numberYears
    int numberYears = readNumberOfYears();
    // data validation to ensure that the numberYears is greater than 0
    while (numberYears <= 0.0){
        cout << "The number of years must be greater than zero" << endl;
        numberYears = readNumberOfYears();
    }

    // converts the percent value of interest rate to a decimal for present value calculation
    double interestRate = percentInterestRate / 100;
    // calls the function presentValue to calculate the present value
    double presentValue = calculatePresentValue(futureValue, interestRate, numberYears);
    // calls the function to display the programs inputs and calculations
    displayResults(presentValue, futureValue,percentInterestRate,numberYears);

    return 0;
}

// function that reads the present value
// prompts user and returns the value to main
double readFutureValue(){
    cout << "Enter future value" << endl;
    double futureValue;
    cin >> futureValue;
    return futureValue;
}
// function that reads the annual interest rate value
// prompts user and returns the value to main
double readAnnualInterestRate(){
    cout << "Enter annual interest rate" << endl;
    double interestRate;
    cin >> interestRate;
    return interestRate;
}

// function that reads the number of years value
// prompts user and returns the value to main
int readNumberOfYears(){
    cout << "Enter number of years" << endl;
    int numberYears;
    cin >> numberYears;
    return numberYears;
}

// function that calculates the present value
// uses the formula for present value and returns the calculation to main
double calculatePresentValue(double futureValue, double interestRate, int numberYears){
    double presentValue;
    presentValue = futureValue / (pow((1+ interestRate), numberYears));
    return presentValue;

}
// function displays the inputs and calculations to main
// uses set precision to output the values with the desired precision
void displayResults(double presentValue, double futureValue, double percentInterestRate, int numberYears){
    cout << "Present value: $" << setprecision(2) << fixed << presentValue << endl;
    cout << "Future value: $" << setprecision(2) << fixed << futureValue << endl;
    cout << "Annual interest rate: " << setprecision(1) << fixed << percentInterestRate << "%" << endl;
    cout << "Years: " << numberYears << endl;
}
