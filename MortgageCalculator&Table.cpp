/*
Troy Kubanka
10/16/2021
Created an amortization table for a home mortgage, and included my program to calculate the monthly payment amount and include Private Mortgage Insurance (PMI). 
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
   int MonthlyPayments, PaymentNumber, i;
   double PurchasePrice, AnnualInterest, DownPayment, InterestRate, DP, loan, PMT, InterestPayment, InterestSum, PrincipalPayment, PrincipalBalance, PrincipalSum, PMI, PMICount, PMISum, base, expo, exponent; 
   
   //User enters their data 
   cout << "We are going to create a mortgage calculator and table given your data! You will need to input your purchase price, annual interest rate, number of monthly payments, and your down payment percentage. Please enter all of your dollar amounts in US ($) dollars." << endl << endl << "First, enter your purchase price here, between $0 and $10000000: $";
   cin >> PurchasePrice;
   while(PurchasePrice <= 0 || PurchasePrice >= 10000000)
   {
      cout << endl << "Error! Your purchase price should be greater than $0 and less than $10000000. Please enter your purchase price again. " 
       << endl << "Purchase price: $";
      cin >> PurchasePrice;
   }
   cout << endl << "Now, enter your annual interest rate, but do not include the (%) label with your answer: ";
   cin >> AnnualInterest;
   while(AnnualInterest <= 0 || AnnualInterest > 100)
   {
      cout << endl << "Error! Your annual interest, as a percent, should be greater than 0 and less than 100. Please enter your annual interest rate again. "
      << endl << "Annual interest (%): ";
      cin >> AnnualInterest; 
   }
   cout << endl << "Next, enter your number of monthly payments: ";
   cin >> MonthlyPayments;
   while(MonthlyPayments <= 0)
   {
      cout << endl << "Error! Your number of monthly payments should be greater than 0. Please enter your number of monthly payments again. "
      << endl << "Monthly payments: ";
      cin >> MonthlyPayments; 
   } 
   cout << endl << "Finally, enter your down payment as a percentage, but do not include the (%) label with your answer. "
   << endl << "Down payment: "; 
   cin >> DownPayment;
   while(DownPayment < 0 || DownPayment > 100)
   {
      cout << endl << "Error! Your down payment percentage should be greater than or equal to 0% and less than or equal to 100%. Please enter your down payment again. "
      << endl << "Down Payment: ";
      cin >> DownPayment;
   }  
   
   //Down payment percentage 
   if(DownPayment >= 0 && DownPayment < 5)
   {
      PMI = 1.030; //percent
   }
   else if(DownPayment >= 5 && DownPayment < 10)
   {
      PMI = .875; //percent
   }
   else if(DownPayment >= 10 && DownPayment < 15)
   {
      PMI = .675; //percent
   }
   else if(DownPayment >= 15 && DownPayment < 20)
   {
      PMI = .375; //percent
   }
   else
   {
      PMI = 0;
   }    

   //Calculation for the loan and monthly payment
   InterestRate = (1.000/12.000) * (AnnualInterest/100);
   DP = PurchasePrice - (PurchasePrice * (DownPayment/100));
   if(DownPayment == 0)
   {
      loan = PurchasePrice;
   }
   else
   {
      loan = PurchasePrice - DP; 
   } 
   base = (1+InterestRate);
   expo = (-MonthlyPayments);
   exponent = pow(base, expo);
   PMT = (InterestRate * DP) / (1 - exponent); 
   cout << endl << endl << "Here is your monthly payment amount: $" << fixed << showpoint << setprecision(2) << PMT << endl << endl;
   cout << "And Here is your mortgage table:" << endl << endl; 

   //line seperation 
   for(i = 0; i < 125; i++)
   {
      cout << "-";
   }
   //table
   cout << endl << endl << setw(73) << "Mortgage Table" << endl << setw(73) << "--------------" << endl << endl;
   cout << setw(5) << "Payment Number" << setw(30) << "Interest Payment" << setw(30) << "Principal Payment" << setw(30) << "Principal Balance" << setw(19) << "PMI" << endl;
   cout << setw(38) << "($)" << setw(30) << "($)" << setw(30) << "($)" << setw(25) << "(%)" << endl;
   cout << setw(5) << "--------------" << setw(30) << "----------------" << setw(30) << "-----------------" << setw(30) << "-----------------" << setw(20) << "-----" << endl;
   //calculations and while loop and if/else
   PaymentNumber = 0;
   PrincipalBalance = PurchasePrice;
   PMICount = 0;
   InterestSum = 0; 
   PrincipalSum = 0;
   cout << setw(14) << PaymentNumber << setw(90) << setprecision(2) << PrincipalBalance << endl;   
   while(PrincipalBalance >= 0)
   {
      PaymentNumber += 1;
      InterestPayment = (1.000/12)*(AnnualInterest/100)*PrincipalBalance;
      InterestSum += InterestPayment;
      PrincipalPayment = PMT - InterestPayment;
      PrincipalSum += PrincipalPayment;   
      PrincipalBalance = PrincipalBalance - PrincipalPayment; 
      cout << setw(14) << PaymentNumber << setw(30) << fixed << showpoint << setprecision(2) << InterestPayment << setw(30) << PrincipalPayment << setw(30) << PrincipalBalance << setprecision(3) << setw(20) << PMI << endl;    
      if(PrincipalBalance < (.8*PurchasePrice))
      {
         PMI = 0;
      }
      else if(PrincipalBalance > (.8*PurchasePrice))
      {
         ++PMICount;
         PMISum = loan * PMICount * (PMI/100);  
      }
   } 
   cout << endl << setw(44) << "----------" << setw(30) << "----------" << setw(50) << "----------"; 
   cout << endl << endl << setw(44) << setprecision(2) << InterestSum << setw(30) << PrincipalSum << setw(50) << PMISum << endl;    

   return 0; 
}
