/*******
 * Hannah Maung
 * Assignment 4
********/

// libraries 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath> 
#include <string.h>

using namespace std;


// calls all the functions
char * get_sentence();  	
bool in_range(int l, int h, int v); 
bool alphanumeric(char &c); 
bool alpha(char &c); 
char * purge_string (char *str); 
char * purge_string2 (char *str); 
void is_palindrome(char *sen); 
int numcount_words(); 
int count_words(char *input);
string * search_words (int number);
char * purge_string3 (char *number);
void frequency_givenwords(int count_words, string * search_words, char *sen); 
int check_words(string input);
void to_upper(string &input);
void frequencyall(char *sen);

int main() {

	// while loop which runs the program 
	// asks user which task they want to do
	// prompts the user if they want to do it again  
	int run = 1;
	while(run){
		int choice;
	        cout << "Do you want to do the palindrome detector (1), frequency of given words (2), or frequency of all words (3)? ";
	        cin >> choice;
		cin.ignore();

		// if user enters 1, then the program checks if the input is a palindrome or not 
		if (choice == 1) {	
			char * sen = get_sentence();
			is_palindrome(sen);
		}	
		// if the user enters a 2, then the program checks if the entered words are in the phrase and how many there are 
		else if (choice == 2) {
				// calls functions 
			char * sen = get_sentence(); 
			int wordcount = numcount_words(); 
			string * searchwords = search_words(wordcount); 
			frequency_givenwords(wordcount, searchwords, sen); 
		}

		cout << "Would you like to make another search? (1 = yes 0 = no): ";
		cin >> run;
	}
	
}

// char pointer, creates function called get_sentence which takes in an integer called option 
char * get_sentence()  {	
	// creates an array of 256 characters 
	char str[256];
	// asks user to enter a sentence
	cout << "Enter a sentence" << endl; 
	cin.getline(str,256); 
 
	// creates size of c style string 
	int size = strlen(str) +1; 
	
	// if statement that if option is 1, then it calls purge_string(str) 
	char * sen = purge_string(str);
	return sen;
 
}

// creates a bool functino called in_range, takes in integers called l, h, and v 
bool in_range(int l, int h, int v) {
	// if statement saying that if v>=l and v<=h, then return true 
	if(v>=l && v<=h){
		return true;
	}	
}
// creates a bool function called alphanum
bool alphanumeric(char &c) {
	// if the string does not have a letter or number	
	if(!(in_range('A','Z',c) || in_range('a','z',c) || in_range('0','9',c))){
		return false;
	}
	// else if its not in range then return true, else make it all capital letters by subtracting 32 
	else{
		 if(!in_range('a','z',c)){
                        return true;
                } 
                else{
                        c = c - 32;
                        return true;
	}
}	 


}

// creates a bool function called alpha, same thing as alphanumeric but it does not take in numbers into account 
bool alpha(char &c) {
	
	if(!(in_range('A','Z',c) || in_range('a','z',c))){
		return false;
	}
	else{
		if(!in_range('a','z',c)){
			return true;
		}
		else{
			c = c - 32;
			return true;
		}
	}

}


// return true if str is palindrome, false otherwise
char * purge_string (char *str) {
	// creates string length of str for c style strings 
	int run = strlen(str); 
	int pos = 0; 
	// creates new array 
	char* strl = new char[run]; 

	// for loop purging through string by calling alphanumeric 
	for (int i = 0; i < run ; i++) {
		if (alphanumeric(str[i])) {
			strl[pos++] = str[i];
		}
	}
	
	strl[pos] = '\0';
	// ignores spaces 
	for(int i = 0; i < pos; i++){
	//	cout << " " << strl[i];
	}

	return strl; 
}
// same thing as purge_string but it calls alpha, but alphanumeric 
char * purge_string2 (char *str) {

	int run = strlen(str);
        int pos = 0;

        char* strl = new char[run];


        for (int i = 0; i < run ; i++) {
                if (alpha(str[i])) {
                        strl[pos++] = str[i];
                }
        }

        strl[pos] = '\0';

        for(int i = 0; i < pos; i++){
                cout << strl[i];
        }

        return strl;

}

// creates function called is_palindrome which takes in paramters *sen 
void is_palindrome(char *sen) {

	// calls function 
	char * get_sentence();
	int size = strlen(sen);
	int t = 0;
	// for loop
	for (int i = 0; i < size ; i++) {
		// if statement checking if the beginning to the end of the phrase in the same 
		if (sen[i] != sen[size-i-1]) {
			t = 1;
			break;
	}
}
	// if t = 1 then print that it is not a palindrome 
	if (t) {
		cout << endl << sen << " is not a palindrome" << endl;
	}
	// else then it is a palindrome 
	else {
		cout << endl <<  sen << " is a palindrome" << endl; 
}

}



// this is for part 3 but i did not fully figure it out 
/*
int count(char *sen) {

	int c = 1;
	for (int i = 0; i < strlen(sen); i++) {
		if (sen[i] == ' '){
			cout << "space found" <<endl;	
			c++;
		}
		cout << sen[i] <<endl;
	}
	return c; 

}


void frequencyall(char *sen) {


	int counter = 1;

	for(int i = 0; i < count_words(sen); i++){
		counter++;
	} 

	char ** words = new char* [counter];
	words[0] = strtok(sen," ");
	
	for (int i = 1; i < counter; i++) {
		words[i] = strtok(NULL," ");
	}
	for (int i = 1; i < counter; i++) {	
		cout << words[i] << endl; 
	}

	

}

*/ 
	
// creates function called numcount_words which is an int 
int numcount_words() {
	// asks the user how many words they want to search for 
        int number = 0;
        cout << "How many words do you want to search for? " << endl;
        string input;
        cin >> input;
	// converts string to integer 
        number = atoi(input.c_str());
        return number;
}


// creates function called count_words which takes in *input 
int count_words (char *input) {
	// creates a for loop which looks for spaces in the input 
        int c = 1;
        for (int i = 0; i < strlen(input); i++) {

                if (input[i] == ' '){
			c++;
		}
        }
        // returns value 
	return c; 

}
// creates a string function called search_words which takes in an int number 
string * search_words (int number) {
	// creates string called search 
	string * search; 
	// creating an array called search 
	search = new string[number];
	// creating a string called input and word
	string input, word;
	// for loop which asks the user what word they want to search for
	for (int i = 0; i < number; i++) {
		cout << endl << "Enter the word(s) that you want to search for: ";
		cin >> input; 
		// if the input is a bad input, then it reprompts the user to enter a good input 
		while(check_words(input)){
			cout << "Please enter a valid word: ";
			cin >> input;
		}
		// calls functions 
		to_upper(input); 			 
		word = input; 
		search[i] = word; 
	}
	
	return search; 
}

// creats void function called to_upper which takes in a string input 
void to_upper(string &input) {
	// creates a variable called length which is the input length 
	int length = input.length();
	int count = 0;
	// for loop which turns all lower case letters to upper cases letters using the ascii table values 
	for (int i = 0; i < length; i++) {

		if (input.at(i) >= 97 && input.at(i) <= 122) {
		
			input.at(i) = input.at(i) - 32;
		}

	}

}
// creates void function called frequency_givenwords which takes in the parameters count_words, search_words and sen 
void frequency_givenwords(int count_words, string * search_words, char *sen) {
	// creates an array of count_words
	int m[count_words]; 
	// for loop indexing the array m with i 
	for(int i = 0; i < count_words; i++){
		m[i]=0;
	}
	// for loop which checks if the words that the user wanted to search for is in the string 
	for (int i = 0; i < count_words; i++) {
		for (int a = 0; a < strlen(sen); a++) {
			int match = 0; 
			for (int b = 0; b < search_words[i].length(); b++) {
				// if statement searching if there is a match 
				if (sen[a+b] == (search_words[i].at(b))) {
					match++; 
				}
				// if statement searching for letters in the array 
				if (match == search_words[i].length()) {
					if (sen[a+b+1] >= 'a' && sen[a+b+1] <= 'z') {
						m[i] = m[i];
					}
					
					else if (sen[a+b-match] >= 'a' && sen[a+b-match] <= 'z') {
						m[i] = m[i]; 
					}	
					// else add one to array m[i]
					else {
						m[i] = m[i]+1; 
					}	
				}
			}
		}

	}	
	// prints out the word frequencies using a for loop 
	cout << endl << "Word Frequencies: " << endl << endl;
	for (int i = 0; i < count_words; i++) {
		cout << search_words[i] << " : " << m[i] << endl; 
	}
}

// creates function called check_words which takes in parameters string input. it purges through the string to get rid of spaces, symbols and numbers 
int check_words(string input){
	int flag = 0;
	for(int i = 0; i < input.length(); i++){
		if(input.at(i) >= 'a' && input.at(i) <= 'z'){
			flag = flag;
		}
		else if(input.at(i) >= 'A' && input.at(i) <= 'Z'){
			flag = flag;
		}
		else{
			flag++;
		}
	}
	if(flag != 0){
		return 1;
	}
	return 0;
}

	
