/********************
 * Program: assignment2.cpp
 * Author: Hannah Maung 
 * Date: 10/23/19
 * Description: 
 * Input:
 * Output:
 * ******************/

#include <iostream> // include a library for inputs and outputs 
#include <string>
using namespace std; 

// calls in the following functions 
bool check_range(int x);
bool is_capital( char letter);
bool is_even( int num);
bool is_odd ( int num);
int equality_test(int num1, int num2);
bool numbers_present(char str);
bool float_is_equal( float num1, float num2);
bool is_int( char num);
bool numbers_present(string str);
bool letters_present( string str);
bool contains_sub_string(string phrase, string sentence);
int word_count (string words); 
void to_upper(string words); 
void to_lower( string words);
int get_int();

int main() {
/********************************
Function: check_range()
Description: indicated if the provided number is in the specified range
Parameters:  int lower_bound, int upper_bound, int test_value 
Pre-conditions: integrer 
Post-conditions: tells you if the number is in the range or not 
********************************/ 
	string str;

	int x; // creates variable x 

	cout << endl << "Testing check_range(20)" << endl; //prints out what function that is being tested 
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f1  = check_range(20); // hard codes what number is being inputted for x for check_range function 

	cout << endl << "Testing check_range(300)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl;  // prints out expected output 
	bool f2 = check_range(300);  // hard codes what number is being inputted for x for check_range function 

	cout << endl << "Testing is_capital(C)" << endl; // prints out what function is being tested 
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f3 = is_capital('A'); // hard codes what letter is being inputted for is_capital function 

	cout << endl << "Testing is_capital(a)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out expected output 
	bool f4 = is_capital('a'); // hard codes what letter is being inputted for is_capital 

	cout << endl << "Testing is_even(60)" << endl; // prints out what function is being tested
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f5 = is_even(60); // hard codes an even number as an input for is_even

	cout << endl << "Testing is_even(69)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out expected output 
	bool f6 = is_even(69);  // hard codes an odd number as an input for is_even 

	cout << endl << "Testing is_odd(79)" << endl; //prints out what function is being tested 
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f7 = is_odd(79); // hard codes an odd number as an input for is_odd

	cout << endl << "Testing is_odd(80)" << endl; //prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out the expected output 
	bool f8 = is_odd(80); // hard codes an even number an an input for is_odd 
	
	cout << endl << "Testing equality_test(2,6)" << endl; // prints out what function is being tested 
	cout << "Expected: -1" << endl; // prints out the expected output 
	int f9 = equality_test(2,6); // hard codes num 1 < num 2 so it prints out a -1 
	
	cout << endl << "Testing equality_test(3,3)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out the expected output 
	int f10 = equality_test(3,3); //hard codes two numbers equal to each other so it prints out a 0 
	
	cout << endl << "Testing equality_test(6,2)" << endl; //prints out what function is being tested 
	cout << "Expected: 1" << endl; // prints out the expected output value 
	int f11  = equality_test(6,2); // hard codes num 1 > num 2 so it prints out a 1 

	cout << endl << "Testing float_is_equal(8.3,8.0)" << endl; // prints out what function is being tested 
	cout << "Expected: It is within the range of 0.5" << endl; // prints out expected value 
	bool f12  = float_is_equal(8.3,8.0); // hard codes if the number is within the range of 0.5 

	cout << endl << "Testing float_is_equal(8.3,7.2)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out expected value
	bool f13  = float_is_equal(8.3, 7.2 ); // hard codes the numbers if they are within a range of 0.5 

	cout << endl << "Testing is_int(9)" << endl; // print out what function is being tested 
	cout << "Expected: 1" << endl; // prints out expected value 
	bool f14 = is_int('9'); // hard codes the number being tested if it is an integer or not 

	cout << endl << "Testing is_int(l)" << endl; // prints out what function is being tested
	cout << "Expected: 0" << endl; // prints out expected output 
	bool f15 = is_int('l'); // hard codes input being tested if it is an integer or not 
		
	cout << endl << "Testing numbers_present(7hf8)" << endl; // prints out what function is being tested 
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f16 = numbers_present("h7f8"); // hard codes input being tested if there are numbers present 


	cout << endl << "Testing numbers_present(fsdf)" << endl; // prints out function is being tested 
	cout << "Expected: 0" << endl;  // prints out expected output 
	bool f17 = numbers_present("fsdf"); // hard codes input being tested if there are numbers present 

	cout << endl << "Testing letters_present(ff55)" << endl; // prints out what function is being tested
	cout << "Expected: 1" << endl; // prints out expected output 
	bool f21 = letters_present("ff55"); // hard codes input being tested if there are letters present 

	cout << endl << "Testing letters_present(7777)" << endl; // prints out what function is being tested 
	cout << "Expected: 0" << endl; // prints out expected output 
	bool f22 = letters_present("543"); // hard codes inout being tested if there are letters present 
	
	cout << endl << "Testing contains_sub_string(computer science is awesome, is awesome)" << endl;
        cout << "Expected: 1" << endl;
        bool f24 = contains_sub_string("computer science is awesome" , "is awesome");

	cout << endl << "Testing contains_sub_string(computer science is awesome, very cool)" << endl;
	cout << "Expected: 0" << endl;
	bool f25 = contains_sub_string("computer science is awesome" , "very cool"); 	

	cout << endl << "Testing word_count(computer science is awesome)" << endl; // prints out what function is being tested 
	cout << "Expected: 4" << endl;  // prints out expected output 
	int f18 = word_count("computer science is awesome"); // hard codes sentence input 

	cout << endl << "Testing to_upper(haNNah)" << endl; // prints out what function is being tested 
	cout << "Expected: HANNAH" << endl; // prints out expected output 
	to_upper("haNNah"); // hard codes sentence input 

	cout << endl << "Testing to_lower(HAnnAH)" <<  endl; // prints out what function is being tested 
	cout << "Expected: hannah" << endl; // prints out expected output 
	to_lower("HAnnAH");  // hard codes sentence input 
	
	get_int(); //calls in function 

}

/************
Function: check_range()
Description: indicated if the provided number is in the specified range
Parameters:  int lower_bound, int upper_bound, int test_value 
Pre-conditions: integrer 
Post-conditions: tells you if the number is in the range or not 
********************************/

// creates function called check range, taking in integer x as an input 
bool check_range(int x)
{
  	// if statement, saying that if x is 1-100, it prints out PASS
        if ((x >= 1) && (x <= 100)) {	

               cout << "PASS" << endl;

        }
	// else if x is not 1-100, it prints out FAIL
        else {

                cout << "FAIL" << endl; 

        }

}

/**********************************
 * Function: is_capital()
 * Description: indicates if the given character is a capital letter 
 * Parameters: char letter 
 * Pre-conditions: takes in letter
 * Post-conditions: tells you if the character is a capital or not
**********************************/

// creates function called is_capital, taking in a letter as in input 
bool is_capital( char letter) 
{
	// if statement, saying that if the letter is an uppercase, it prints out PASS
	if ((letter >='A') && (letter <='Z')) {

		cout << "PASS" << endl; 
	}
	// if statement, saying that if the letter is a lowercase, it prints out FAIL 
	else {
		cout << "FAIL" << endl; 

	}

}


/************************************
 * Function: is_even() 
 * Description: indicates if a given number is even 
 * Parameters: int num 
 * Pre-conditions: takes in a number
 * Post-conditions: tells you if the number is even or not 
***********************************/

// creates function called is_even, taking in integers as inputs 
bool is_even( int num) 
{
	// if statement, saying if the remainder is zero then it is even and it prints out PASS
	if (num%2 == 0) {

		cout << "PASS" << endl;
	}
	
	// else if the remainder is not zero, it is an odd number, and it prints out FAIL 

	else {

		cout << "FAIL" << endl;

	}
}

/************************************
 * Function: is_odd()
 * Description: indicates if a given number is odd 
 * Parameters: int num 
 * Pre-conditions: takes in a number
 * Post-conditions: tells you if the number is odd or not 
 ************************************/

// creates function called is_odd, takes in an integer as an input  
bool is_odd ( int num)
{
	// if statement saying that if the remainder is zero, then it is an even number so it prints out FAIL 
	    if (num%2 == 0) {

                cout << "FAIL" << endl;
        }
	// else if the remainder is not zero, it is an odd number, and it prints out PASS
       else {
		cout << "PASS" << endl; 

}

}

/**********************************
 * Function: equality_test()
 * Description: tests num1 against num2, returns -1 if num 1 < num 2, returns 0 of num 1 == num 2, returns 1 of num1 > num2 
 * Parameters: int num1 and int num2 
 * Pre-conditions: takes in number 
 * Post-conditions: decides if the numbers are equal, greater or less than 
********************************/

// creates a function called equality_test, taking in two integers as inputs 
int equality_test(int num1, int num2 )
{
	// if statement, saying that if num 2 is greater than num 1, it prints out a -1 
	if (num1 < num2) {
	
		cout << "-1" << endl; 

	} 
	// else if the two numbers are equal to each other, it prints out a zero 
	else if (num1 == num2) { 
		
		cout << "0" << endl; 
	}
	// else if num 1 is greater than num 2, it prints out a 1 
	else  {

		cout << "1" << endl; 

	}

}


/***************************************
 * Function: float_is_equal()
 * Description: tests if num1 == num2 within a certain precision
 * Parameters: float num1 and float num2, float precision
 * Pre-conditions: takes in number 
 * Post-conditions: decides if they numbers are equal to each other 
**************************************/

// creates function falled float_is_equal, taking in two decimal numbers as inputs 
bool float_is_equal( float num1, float num2 ) 
{ 
	// if statement saying that if num1-num 2 is within the range of 0.5, it prints out the following cout
	if ( (num1 - num2) <= 0.5) {

		cout << "It is within the range of 0.5" << endl; 

	}
	// if the first condition is not true, then FAIL is printed 
	else {

		cout << "FAIL" << endl; 

	}
}

/*************************************
 * Function: is_int()
 * Description: tests if num1 == num2 within a certain precision
 * Parameters: float num1 and float num2, float precision
 * Pre-conditions: takes in number 
 * Post-conditions: decides if they numbers are equal to each other 
************************************/

// creates function called is_int, taking in a character num as an integer 
bool is_int( char num)

{ 
	// declares variables 
	int x;
	x = int(num);

	// if statement saying that if num is within the following acii numbers, it prints out PASS
	if (num >= 48 && num <= 57) {

		cout << "PASS" << endl; 

	}

	else  {
	// if the first statement is not true, then it prints out FAIL
		cout << "FAIL" << endl;

	}
}


/**************************************
 * Function: numbers_present()
 * Description: indicates if the given string contains numbers 
 * Parameters: string sentence
 * Pre-conditions: takes in a string parameter 
 * Post-conditions: returns a value to tell if the string has a number 
**************************************/

// creates function called numbers_present, taking in string str 
 
bool numbers_present(string str) {
 
	// declares variables   
	int length = str.length();
	int count = 0; 	

	// for loop, starts at 0, ends at length of the string, counts up by one 
	for (int a = 0 ; a < length ; a++) {

		// if statement, if the length is between 0-9
		if (str.at(a) < '0' || str.at(a) > '9') {
			
		
		}
		// else it adds 1 to count variable 
		else {
			count = count + 1 ; 
			
	}
	
}
	// if statement, if count is greater than 0 then PASS is printed  
	if (count > 0) { 
		cout << "PASS" << endl;
	}
	//else it prints out FAIL 
	else {
		cout << "FAIL" << endl; 

}
}

/***********************
 * Function: letters_present()
 * Description: indicates in the provided string contains letters 
 * Parameters: string sentence 
 * Pre-conditions: takes in a string parameter 
 * Post-conditions: returns a value to tell if the string contains letters
***********************/

// creates function called letters_present, takes in string str 
bool letters_present( string str) {

	// declares variables 
	int length = str.length(); 
	int count = 0; 

	// starts at 0, ends at length of string, adding one each time 
	for (int a = 0; a < length ; a++) { 

		// if statement, if string contrains letters 
		if ((str.at(a) >= 48) && ( str.at(a) <= 57)) {
		
	}
	
	// else 1 is added to variable count 
	else {
		count = count + 1; 
				
	}
}
	// if statement, if count is greater than zero, PASS is printed out 
	if (count >  0) {

		cout << "PASS" << endl; 

	}
	// else FAIL is printed out 
	else { 

		cout << "FAIL" << endl; 
	
}
}


/****************************************
  * Function: contains_sub_string()
  * Description: indicates if substring exists in the sentence 
  * Patameters: string sentence 
  * Pre-conditions: takes in a string
  * Post-conditions: returns a value to tell you if the string exists in the sentence 
******************************************/



// creates function called contains_sub_string, takes in two strings 
bool contains_sub_string(string phrase, string sentence) {

	int x1 = phrase.length();
	int x2 = sentence.length(); 

	int x = 0;
	
	for (int a = 0; a <= (x2-x1); a++) { 
		for (int a1 = 0 ; a1 <= (x2-x1); a1++) {

			if (sentence[a+a1] != phrase[a1]) {
				x = 1; 
				break; 
			}
		}
	}
	if (x ==0 ) {
		cout << "PASS" << endl; 
 	}
	else {
		cout << "FAIL"<< endl;
	}
}

/*************************
 * Function: word_count()
 * Description: provides the number of words in a given string 
 * Parameters: string sentence 
 * Pre-conditions: takes in the string
 * Post-conditions: returns a value that represents the number of words in the string 
*************************/ 

// creates function called word_count, takes in string 
int word_count (string words) {
string str;
	
	// declares variables 
	int length = words.length();
        int count = 0;
	
	// for loop, starting at zero, goes to length of string, goes up by one 
        for (int a = 0 ; a < length ; a++) {
		
		// if statement, counts how many spaces there are in the given string 
                if (words.at(a) == 32) {
		// creates counter variable 
		count = count + 1; 

		}

               
}
	// adds one to the count variable 
	count = count + 1; 
	// prints out the number of words 
	cout << "number of words: " << count << endl; 

}

/*****************
 * Function: to_upper()
 * Description: capitalizes all letters in a given string and leaves all non-letter characters unchanged * Parameters: string sentence 
 * Pre-conditions: takes in string 
 * Post-conditions: capitalizes letters 
*****************/

// creates function called to_upper, takes in string 
void to_upper(string words) { 
string str; 

	// declares variables 
	int length = words.length();
        int count = 0;

	// for loop, starting at zero, goes to length of the string, goes up by one
        for (int a = 0 ; a < length ; a++) {

		// if statement, if there are lowercase letters then it changes it to uppercase 
                if (words.at(a) >= 97 && words.at(a) <= 122) 

                words.at(a) = words.at(a) - 32; 

                }
	// prints out string 
        cout  << words << endl;

}

/**************
 * Function: to_lower()
 * Description: makes all letters lowercase in a given string 
 * Parameters: string sentences 
 * Pre-conditions: takes in string
 * Post-conditions: makes all letters lowercase 
**************/

// creates function called to_lower, takes in string 
void to_lower( string words) { 

string str;

	// declares variables 
        int length = words.length();
        int count = 0;

	// for loop, starting at zero, goes to length of the string, goes up by one 
        for (int a = 0 ; a < length ; a++) {

		// if statement, if the string has an uppercase letter it changes it to lowercase 
                if (words.at(a) >= 65 && words.at(a) <= 90)

                words.at(a) = words.at(a) + 32;

                }
	// prints out string 
        cout  << words << endl;

}


/*************
 * Function: get_int()
 * Description: takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer 
 * Parameters: string prompt 
 * Pre-conditions: takes in string 
 * Post conditions: returns integer 
**********/

// creates a function called get int(), takes in 
int get_int(){
	string num;	
	
	// asks user to input a number 
	cout << "Give me a number: ";
	cin >> num;
	
	// declares a variable x
	int x = 0;
	
	// creates a for loop, starts at 0, ends at length of num, goes up by one 
	for(int i = 0; i < num.length(); i++){
		// if there is an integer 
		if(!(char(num.at(i)) < '0') && (char(num.at(i)) > '9')){
			x = 1;
		}
	}
	
	// if x is equal to one, print the following statement	
	if(x==1){
		cout << "That is not an integer" << endl;
	} // else prints the following statement 
	else{
		cout << "That is an integer" << endl;
	}	
}
