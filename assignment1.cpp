/************************
 * Program: Calculate Gross Income and Taxes for a Salesperson 
 * Author: Hannah Maung 
 * Descripton: a program that calculates and displays the gross income, taxes that must be paid by a car salesperson, and the remaining income 
 * Input: monthly salary, number of months worked in a year, cost of a car, number of cars sold, number of misconducts observed, tax year, state
 * Output: gross income, taxes, 
 * ************************/

#include <iostream> //library for input (cin) and output (cout)
#include <ctime> // time()
#include <cstdlib> // rand(), srand()
#include <math.h> // pow()

using namespace std; 

int main()

{
	// creates variables 
	int salary;
	int months;
	int carcost;
	int carssold;
	int misconducts;
	int taxyear;
	char state;

//allows user to input an answer and saves it to that variable with cin 
	cout << "What is your monthly salary?" << endl;
	cin >> salary;

	cout << "How many months have you worked this year?" << endl;
	cin >> months;

	cout << "What is the cost of the car?" << endl;
	cin >> carcost;

	cout << "How many cars did you sell in the past year?" << endl;
	cin >> carssold;

	cout << "How many misconducts have you observed in the past year?" << endl;
	cin >> misconducts;

	cout << "What is the tax year, enter 1 for 2017, 2 for 2018" << endl;
	cin >> taxyear;

	cout << " What state are you in, enter A, B, or C?" << endl;
	cin >> state;


	float annualsalary; //creates a variable annualsalarly 
	annualsalary = salary *(months); //calculates annual salary with inputs 
	
	srand(time(NULL)); //sets the starting point, NULL meaning 0 and time(NULL) will give the current
		  	   //time
	int r = rand() % 5 + 5; //generates a random number from 5 to 10 
	float average = (r/100) +1; //
	float profit; //creates variable called profit 
	profit = carssold * (average - carcost); //calculates the profit 

	int deductions; //creates variable called deductions 
 
	// if statement 
	if (misconducts == 0) { //if misconducts is observed as zero, there is no deduction 
		deductions == 0;
		} 
		else { // else if it is more than zero, then the amount of deduction gets doubled as the
		       //number of misconducts observed increases 
		deductions = (100 * pow(2,(misconducts-1))); 
		}

	// calculates the gross income 
	float result = annualsalary + (0.02* profit) - deductions; 
	
	// if statement for input errors 
	if (months > 12 ) { //if user inputs a number more than 12, it prints out a warning statement 
		cout << "Enter an accurate number of months" << endl;
		cin >> months; 
		} //if user enters something other than A,B, or C, a warning is printed 
	if (state != 'A' && state != 'B' && state != 'C') {
		cout << "Enter an accurate letter, A, B or C" << endl;
		cin >> state;
		} //if user enters something other than 1 or 2, a warning is printed out 
	if (taxyear !=1  && taxyear !=2) {
		cout << "Enter an accurate number for your tax year" << endl;
		cin >> taxyear; 
		}

	float taxes; //creates a variable called taxes 

//if user inputs 1 for 2017, the following if statements occur 
	if (taxyear == 1) { //If user enters 1 for 2017 tax year and has state A, the following occurs 
		if (state == 'A') {
			taxes = (0.06 * result); //calculates taxes of the car salesperson 
		} //if user enters 1 for 2017 tax year and is in state B, the following occurs 
		if (state == 'B') { 
			if (result < 2000) { //if your income is below 2000, you pay $0 
				taxes = 0;
		} //else if your income is between 2000 and 10000, you pay $100 
			else if ((result >= 2000) && (result <= 10000)) {
				taxes = 100;
		} //if above statements are not true, you pay 10% plus $100
			else {
				taxes = (result * 0.10) + 100;
		} 
}
 		// if user enters 1 for 2017 tax year and is in state C, the following occurs 
		if (state == 'C') {
			if (result < 3500) { //if income is below 3500, you will pay 5% 
				taxes = (0.05 * result);
		} //else if your income is between 3500 and 9000, you will pay 7% plus $175
			else if ((result >= 3500) && (result < 9000)) {
				taxes = (0.07 * result) + 175;
		} //else if your income is between 9000 and 125k, you will pay 9% plus $560 
			else if ((result >=9000) && (result < 125000)) {
				taxes = (0.09 * result) +560;
		} //if statements above are not true, you will pay 9.9% plus $11000
			else {
				taxes = (0.099 * result) + 11000;
		}
}
}

//if statement if user enters 2 for 2018 tax year 
	if (taxyear == 2) { 
		if (state == 'A') { //if user has 2018 tax year and is from state A
			taxes = (result * 0.08); //they pay 8% on your income 
		} //if user is from state B and has 2018 tax year
		if (state == 'B') { 
			if (result < 2500) { //if your income is below $2500, you will pay $0 
				taxes = 0;
		} //if your income is between 2500 and 10k, you will pay $115
			else if ((result >= 2500) && (result <= 10000)) {
				taxes = 115;
		} //if statements above are not true, you will pay 10.5% plus $115
			else { 
				taxes = (0.105 * result) + 115;
		} 
}		//if user is from state C and has a 2018 tax year 
		if (state = 'C') { 
			if (result < 3450) { //if user has income below 3450, they will bay 5%
				taxes = (0.05 * result);
		} //else if user has income between 3450 and 8700, they will pay 7% and $172.5
			else if ((result >= 3450) && (result < 8700)) {
				taxes = (0.07 * result) + 172.5; 
		} //if user has income between 8700 and 125k, they will pay 9% plus $560
			else if ((result >= 8700) && (result <= 125000)) {
				taxes = (0.09 * result) + 560;
		} //if statements above are not true, the user will pay 9.9% plus 11k 
			else { 
				taxes = (0.099 * result) + 11007; 

		}
}
} 
	cout << "The gross income is:" << result << endl; //prints out the gross income 
	float remaining; //creates remaining variable 
	remaining = result - taxes; //calculates the remaining 
	float percentage; //creates percentage variable 
	percentage = (0.02 * profit); //calculates 2% of the profit 

	cout << "The randomly generated percent: " << r << endl; //prints out the randomly generaged %
	cout << "The tax you need to pay is: " << taxes << endl; //prints out tax number 
	cout << "Remaining: \n " << remaining; //prints out remaining money 

return 0; 

  }


