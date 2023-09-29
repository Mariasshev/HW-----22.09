#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Payment.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

SYSTEMTIME t;

Payment::Payment()
{
	FIO = ' ';
	year = salary = percent = standing = icome_tax = work_day_in_month = days_worked = accrued_amount = amount_withheld = 0;
}

Payment::Payment(string fio, int y, int pernt, double sal, int dayPerMonth, int daysWorked)
{
	FIO = fio;
	year = year;
	percent = pernt;
	salary = sal;
	work_day_in_month = dayPerMonth;
	days_worked = daysWorked;
}

void Payment::InputData()
{
	string fio;
	int y, pernt, sal, dayPerMonth, daysWorked;
	cout << "Enter FIO: ";
	getline(cin, fio);
	this->FIO = fio;
	cout << "Year the employee started working: ";
	cin >> y;
	this->year = y;
	cout << "Enter salary: ";
	cin >> sal;
	this->salary = sal;
	cout << "Bonus percentage: ";
	cin >> pernt;
	this->percent = pernt;
	cout << "Number of working days this month: ";
	cin >> dayPerMonth;
	this->work_day_in_month = dayPerMonth;
	cout << "Number of days worked: ";
	cin >> daysWorked;
	this->days_worked = daysWorked;
}

double Payment::AccruedAmount()
{
	accrued_amount = (SalaryPerDay() * days_worked) - AmountWithheld() + PercentByDay();
	return accrued_amount;
}

double Payment::AmountWithheld()
{
	amount_withheld = PensionFund() + IncomeTax();
	return amount_withheld;
}

double Payment::PensionFund()
{
	double fund = ((SalaryPerDay() * days_worked) * 1) / 100;
	return fund;

}

int Payment::Standing()
{
	GetLocalTime(&t);
	standing = t.wYear - year;
	return standing;
}

double Payment::SalaryPerDay()
{
	double perDay = (salary / work_day_in_month);
	return perDay;
}

double Payment::IncomeTax()
{
	icome_tax = ((SalaryPerDay() * days_worked) * 13) / 100;
	return icome_tax;
}

double Payment::PercentByDay()
{
	double perct = (SalaryPerDay() * percent) / 100;
	return perct;
}

void Payment::Print()
{
	cout << "Employee`s data:" << endl;
	cout << "FIO: " << FIO << endl;
	cout << "Started work: " << year << endl;
	cout << "Salary: " << salary << endl;
	cout << "Bonus percentage: " << percent << endl;
	cout << "Income tax: " << IncomeTax() << endl;
	cout << "Standing: " << Standing() << endl;
	cout << "Amount withheld: " << AmountWithheld() << endl;
	cout << "Accrued amount: " << AccruedAmount() << endl;
}