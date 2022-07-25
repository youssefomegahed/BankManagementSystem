#include "bm_customers.h"
#include "bm_account.h"
#include "common.h"

//global variables to facilitate use in program
Customer c;
Account a;

//function declarations
void userInterface1();
void userInterface2(int id); 

//main function
int main() 
{

Node* head = NULL; //initializing head to NULL

userInterface1(); //starting the main program


return 0;
} 
//end of main program



//function definitions

void userInterface1() //main interface
{
	int code;

//introductory output
	cout<<endl<<"To add a new customer, enter 1"
	<<endl
	<<"To search for an existing customer, enter 2"
	<<endl
	<<"To delete a customer, enter 3"
	<<endl
	<<"To display all customers, enter 4"
	<<endl
	<<"To search for an account, enter 5"
	<<endl;
	
	cin>>code; //user's input

	if(code==1){ //adding new customer path
	int id;
	int code4;

	do{
 		cout<<endl
 		<<"ID: ";

 		cin >> id;

 		if(c.checkID(c.head, id) == true){

 		c.createCustomer(id);

 	} 

 		cout<<endl
 		<<"To add another customer, enter 1"
 		<<endl
 		<<"To go back to the main menu, enter 2"
 		<<endl;
 		cin >> code4;

 		if(code4 == 2){

 			userInterface1();

 		} else if (code4 != 1 && code4 != 2){
 			
 			cout<<"invalid input."<<endl;

 			userInterface1();
 		}

 	} while(code4 == 1);


	} else if(code==2){ //search for customer path
		int code5;

		cout<<endl<<"To search by ID, enter 1"
		<<endl
		<<"To search by name, enter 2"
		<<endl;

		cin>>code5;

		if(code5 == 1) {
		int id;

		cout<<endl<<"Enter customer's ID: "
		<<endl;

		cin>>id; //capturing ID

		c.searchbyID(c.head, id);

	    userInterface2(id);

		} else if (code5 == 2){
		string first, last;

		cout<<endl<<"(You can enter only first name, only last name, or both)"
		<<endl
		<<"First Name: ";
		cin>> first;

		cout<<"Last name: ";
		cin>> last;

    	c.searchbyName(c.head, first, last);

		userInterface2(c.nameToID(first,last)); //get ID from first or last names and use function userInterface2(id)

		} else {
			cout<<"Invalid input."<<endl;

			userInterface1();

		}


	

	} else if (code == 3){
		int id, code3, code6;

		do{
		cout<<"Enter the ID of the customer you would like to delete: "
		<<endl;
		cin >> id;

		cout << "Are you sure you would like to delete the account with the ID "<<id<<"?"
		<<endl
		<<"If yes, enter 1"
		<<endl
		<<"To go back, enter 2"
		<<endl;
		cin >> code3;

		if(code3 == 1) {

		c.deleteCustomer(&c.head, id);

		cout<<"To delete another customer, enter 1"
		<<endl
		<<"To go back to the main menu, enter 2"
		<<endl;
		cin >> code6;

		if(code6 == 2){

			userInterface1();

		} else if (code6 != 1 && code6 !=2){
			
			cout<<"invalid input."<<endl;

			userInterface1();
		} 
	} else if(code3 == 2){

		userInterface1();

	} else {

			cout<<"invalid input";

			userInterface1();

		}

	} while(code6 == 1);

	} else if (code == 4){

		c.displayAll();

		userInterface1();
	}


	else if (code==5) {
		int accountN;

		cout<<"Account number: ";
		cin >> accountN;
		cout<<endl;

		a.searchAccount(a.head, accountN);

} else {
		cout<<"Sorry, not a valid input. Try again"<<endl; //invalid input

		userInterface1();
	}
} 


void userInterface2(int id){ //interface after searching for a customer
	int code2;

do{
	cout<<endl<<"For account details, enter 1"
	<<endl
	<<"For ATM transaction details, enter 2"
	<<endl
	<<"For customer information, enter 3"
	<<endl
	<<"To go back to the main menu, enter 4"
	<<endl;
	cin >> code2;

	if(code2 == 1){
		int code7;

		do {
		cout<<endl<<"To create an account for this customer, enter 1"
		<<endl<<"To view this customer's accounts, enter 2"
		<<endl<<"To go back, enter 3"<<endl;
		cin >> code7;

		if(code7==1){

			a.createAccount(id);

			userInterface2(id);

		} else if(code7==2){

			a.displayAccounts();

		} else if(code7 == 3){

			userInterface2(id);

		} else{

			cout<<"invalid input."<<endl;

		}
	} while(code7 != 3);

	} else if(code2 == 2){ //transaction details
		int code8;

		cout<<endl<<endl<<"To deposit money into this account, enter 1"
		<<endl<<"To withdraw money from this account, enter 2"<<endl
		<<"To go back, enter 3"<<endl;
		cin >> code8;

		if(code8 == 1){
			int accountNo, amount;

			cout<<endl<<"Enter the number of the account you would like to deposit money into: "<<endl;
			cin >> accountNo;

			cout<<"Enter the amount you would like to deposit: "<<endl;
			cin >> amount;

			a.deposit(a.head, accountNo, amount);

		} else if(code8 == 2){
			int accountNo, amount;

			cout<<endl<<"Enter the number of the account you would like to withdraw money from: "<<endl;
			cin >> accountNo;

			cout<<"Enter the amount you would like to withdraw: "<<endl;
			cin >> amount;

			a.withdraw(a.head, accountNo, amount);

		} else if(code8 == 3){

			userInterface2(id);

		} else {

			cout<<"invalid input."<<endl;

			userInterface2(id);

		}

	} else if(code2 == 3){

		c.displayInfo(c.head, id);

	} else if(code2 == 4){

		userInterface1();
	}

	 else{

		cout<<"invalid input."<<endl;
		
		userInterface2(id);
	}
} while(code2==1||code2==2||code2==3);


} 