#pragma once
#include <string>
#include <iostream>
using namespace std;

class Payment
{
	string FIO;
	int year;
	double salary;
	int percent;
	int standing;
	double icome_tax;
	int work_day_in_month;
	int days_worked;
	double accrued_amount;
	double amount_withheld;
public:
	Payment();		//constructor by default
	Payment(string fio, int y, int pernt, double salary, int dayPerMonth, int daysWorked);		//constructor with params

	void InputData();				//input data
	void Print();					//show data
	double AccruedAmount();			//to calc accrued amount
	double AmountWithheld();		//to calc amount withheld
	int Standing();					//to calc Employee standing
	double SalaryPerDay();			
	double IncomeTax();
	double PensionFund();
	double PercentByDay();
};

