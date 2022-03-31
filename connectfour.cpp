/******
 * Hannah Maung 
 * Assignmnt 5 Connect four 
 * this program implements a game that is played in read life, Connect four
*******/

// libraries
#include <iostream> 
#include <cstdlib> 
#include <string> 

using namespace std; 
// checks if user entered a 1 or 0, returns false if user does not 
bool check_yes(int a) {

	if (a == 1) {
		return 1; 
	}
	else if (a == 0) { 
		return 1; 

	}
	else {
		return 0; 
	}
}


// checks if y is an integer
bool is_int(char y) {
    	// if y is a letter, it returns true, else it returns 0 
        if (y > 48 && y < 57) {
                return 1;
        }
        else { 
                return 0; 
        }
}

// prints out column numbers at the top 
void printer(int cols) {

	for(int i = 1; i < (cols + 1); i++) {

		cout << "  " << i << " " ; 

	}
	cout << endl; 
}

// initializes the 2D array, takes in rows and col as parameters 
char ** initialize(int row, int col) {

	// creates 2D array on the heap 
	char ** a = new char * [row];
 
	// for loop creating columms
	for (int i = 0; i < row; i++){
		a[i] = new char [col];
		
	}
	// makes spaces for each turn space 
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			a[i][j] = ' ';
		}
	}
	
	return a;
}


// deletes the 2D array 
void delete_array(char **a, int row) {
	
	for (int i = 0; i < row; i++) {
		delete [] a[i];
	}
	delete [] a; 

}

// colors a 2D board
void show_board(char** table, int rows, int cols) {

	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{	
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << table[i][j] << " ";
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << table[i][j] << " ";
			else
				cout << "|\033[0m " << table[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}		
}

// checks for 4 pieces in a row of the board, prints out winner statements 
bool win(char **a, int rows, int cols) {
		
		for (int i = 0; i < rows-1; i++) {
	                for (int j = 0; j < cols-1; j++){
	
			if(a[j][i] == 'O' && a[j+1][i+1] == 'O' && a[j+2][j+2] == 'O' && a[j+3][i+3] == 'O') {
			return 1; 
			cout << "Player 1 wins" << endl; 
			}
			if(a[j][i] == 'O' && a[j+1][i+1] == 'O' && a[j+2][i-2]== 'O' && a[j+3][i-3] == 'O') {
			return 1; 
			cout << "Player 1 wins" << endl; 
			}	
			if(a[j][i]== 'X' && a[j+1][i-1] == 'X' && a[j+2][i-2] == 'X' && a[j+3][i-3] == 'X') {
			return 1; 
			cout << "Player 2 wins" << endl; 
			}
			else if(a[j][i]== 'X' && a[j-1][i-1] == 'X' && a[j-2][i-2] == 'X' && a[j-3][i-3] == 'X') {
			return 1; 
			cout << "Player 2 wins" << endl; 
			}
			else if (a[j][i] == 'O' && a[j][i-1] == 'O' && a[j][i-2] == 'O' && a[j][i-3] == 'O') {
			return 1; 
			cout << "Player 1 wins" << endl; 
			}
			else if (a[j][i] == 'O' && a[j-1][i] == 'O' && a[j-2][i] == 'O' && a[j-3][i] == 'O') {
			return 1; 
			cout << "Player 1 wins" << endl;
			}
			else if(a[j][i] == 'X' && a[j][i-1] == 'X' && a[j][i-2] == 'X' && a[j][i-3] == 'X') {
			return 1; 
			cout << "Player 2 wins" << endl; 
			}
			else if (a[j][i] == 'X' && a[j-1][i] == 'X' && a[j-2][i] == 'X' && a[j-3][i] == 'X') {
			return 1;  
			cout << "Player 2 wins" << endl; 
			}
		}	
        	

		return 0; 		
	}
}
// calls move function 
bool move(char **, int , int , int, int );	

//function for two player game
void game(char **a, int rows, int cols) {

	//creates variables 
	int win_check = 0;
	bool full = 0;
	int choice; 
	//bool bad; 
	// while there is no winner, the players keep playing 
		
		do {
		// asks player 1 for a column 
		cout << "Player 1 pick a column";
		cin >> choice; 
		//bad = false; 
		
		// calls function move 
		move(a, rows, cols, choice, 0);	
	
		// asks player 2 for a column
		cout << "Player 2, pick a column";
		cin >> choice; 
		//calls function move 
		move(a, rows, cols, choice, 1);	
		// checks if there is a winner 
		
		win_check = win(a, rows, cols);


		}
		while (!win_check);
	}

	/*
	for (int i = 0; i < choice; i++) {
		if (!(choice => cols && choice <= cols)) {
			cout << "too many columns, try again" << endl; 	
			bad = true; 
			break; 
			}
		}
	} while(bad == true);

	*/

// checks spaces of the board so the piece can be dropped above it 
int check_spaces(char **a, int cols, int rows, int choice){
	int count = 0;
		
	// for loop stating that if there is a space, then count keeps track of that 
	for(int i = 0; i < rows; i++){
		if(a[i][choice-1] == ' '){
			count++;
		}
	}	
	
	if(!count){
		return 0;
	}
	
	return count-1;
}

//the function to place the X's and O's 
bool move(char **a, int rows, int cols, int choice, int player) {
		
	int space = check_spaces(a, cols, rows, choice);
		// for the first player, places an X where there is a space 
		if (player == 0) {
			if (space) {
				(a[space][choice-1] = 'X');
                        	cout << "X" << endl;
                	}
			//if there are no more spaces in that column, print the following message
			else {
				cout << "column is full" << endl;
				return 1; 			
			}
		} 
		// for player 2, place an O where there is a next free space in that column
                else {
			if (space) {
                        	(a[space][choice-1] = 'O');
                         	cout << "O" << endl;
			}
		}
		// calls function, prints updated board after every move 
		printer(cols); 
		show_board(a, rows, cols);		
		return 0;
}


// function for player 1 mode
void game2(char **a, int rows, int cols) {

	srand(time(NULL));
	//creates variables 
        int win_check = 0;
        bool full = 0;
	int choice;; 
	int first; 
	// asks user if they would like to go first 
	cout << "Would you like to go first? (1-yes, 0-no)" << endl;
        cin >> first;

	if (check_yes(first) == 0) {
		cout << "Invalid input, please enter a 1 or 0" << endl;
		cin >> first;
	}
	
	// runs as long as there are no winners 
        while (!win_check){


	// if player picks 1 for yes, then player 1 goes first then the computer 
	if(first == 1) {
                cout << "Player 1 pick a column: ";
                cin >> choice;
                move(a, rows, cols, choice, 0);

		cout << "computer's turn!" << endl;
		// random generator between the column range 
		choice = rand() % cols-1;
                move(a, rows, cols, choice, 1);

                win_check = win(a, rows, cols);
		}
	// else if the player picks 0 for no, then the computer goes first 
	else {
		cout << "computer's turn!" << endl; 
		choice = rand() % cols-1; 
                move(a, rows, cols, choice, 0);
		// user is asked to pick a column after the computer goes 
		cout << "Player 1 pick a column: ";
                cin >> choice;
                move(a, rows, cols, choice, 1);

                win_check = win(a, rows, cols);
        }
}	
}

int main(int argc, char * argv[]) {

	// error handling 
	int flag = 0; 
	if (argc != 4) {
		cout << "Invalid number of arguments" << endl;
		exit(0);
	}
		if(!(atoi(argv[1]) >= 1 && atoi(argv[1]) <= 2)){
			cout << "Invalid number of players" << endl;
			return 0;
		}
		else if(atoi(argv[2]) > 20){
			cout << "Too many columns" << endl;
			return 0;
		}
		else if(atoi(argv[3]) > 20){
			cout << "Too many rows" << endl;
			return 0;
		}
	

	// converts string to integer for number of columns and rows 	
	int cols = atoi(argv[2]);
	int rows = atoi(argv[3]);
	// calls function to initialize the board 
	char ** table = initialize(rows, cols); 

	// runs the game, calls functions, asks user if they want to play the game again 
	int run = 1; 
	do{

	cout << "WELCOME TO CONNECT FOUR" << endl; 
	int player = atoi(argv[1]); 
	cout << "You said player " << player << " mode" << endl; 	

	if (player == 1) {
		game2(table, rows, cols);
	}	
	else {
		game(table, rows, cols); 
	}

	cout << "Do you want to play again? (1-YES,0-NO)" << endl; 
	cin >> run; 
	if (check_yes(run) == 0) {
		cout << "Invalid input, enter a 1 or 0" << endl; 
		cin >> run; 
	}
	}while(run);
}
	


	
