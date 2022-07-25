#ifndef BM_ACCOUNT_H
#define BM_ACCOUNT_H
#include "common.h"
#include "bm_customers.h"

//forward declarations
struct Node;
class Customer;


class Account : public Customer
{
public:
	Node *head, *tail;

	Account(){
		head = NULL;
		tail = NULL;
	}



	void createAccount(int integer){
		Node *temp = new Node;
		temp -> accountNumber = rand() % 1000 + 10000; //randomizes account number
		while(checkAccountNumber(head,temp->accountNumber)==false){ //ensures account number isn't repeated
			temp->accountNumber = rand() % 1000 + 10000;
		}
		temp -> balance = 0;


		cout<<endl<<"What type of account would you like to create? (Current / Saving)"<<endl;
		cin >> temp -> type;

		//ensures specific entries for type of account
		while(temp -> type != "Current" && temp -> type != "current" && temp -> type != "C" && temp -> type != "c" && temp -> type != "Saving" && temp -> type != "S" && temp -> type != "saving" && temp -> type != "s"){
			cout<<endl<<"invalid account type, try again"<<endl;
			cout<<endl<<"What type of account would you like to create? (Current / Saving)"<<endl;
			cin >> temp -> type;
		}
		cout<<endl<<"Account created successfully!"<<endl;
			cout<<"Account number: "<<temp->accountNumber
			<<endl;
			cout<<"Account balance: "<<temp->balance
			<<endl;
			cout<<"Account type: "<<temp->type
			<<endl;
		temp -> next = NULL;

		if(head==NULL){
			head = temp;
			tail = temp;
			temp = NULL;
		} else{
			tail -> next = temp;
			tail = temp;
                                                                                 
		}



	}



	bool checkAccountNumber(struct Node* head, int x){ //checks if account number already exists
		Node *temp = head;
		
		if(head == NULL) return true;

		while(temp!=NULL){
		if(temp->accountNumber == x){
			return false;
		}
		temp = temp->next;
		}
		return true;
	}


	void deposit(struct Node* head, int accountN, int amount){ //add to the account balance
		if(checkAccountNumber(head, accountN)==true){
			cout<<endl<<"Account does not exist. Try again."<<endl;
			return;
		}
		if(head -> accountNumber == accountN){
			head -> balance += amount;

			cout<<endl<<amount<<" EGP have been deposited successfully."<<endl;
			displayAccount(head, accountN);
			return;
		}

		deposit(head->next,accountN,amount);

	}


	void withdraw(struct Node* head, int accountN, int amount){ //subtract from the account balance
		if(checkAccountNumber(head, accountN)==true){
			cout<<endl<<"Account does not exist. Try again."<<endl;
			return;
		}
		if(head -> accountNumber == accountN){
			head -> balance -= amount;
			if(head -> balance < 0){
				cout<<"Account balance cannot be negative. Try again"<<endl;
				return;
			} else {
		    cout<<endl<<amount<<" EGP have been withdrawn successfully."<<endl;
			displayAccount(head, accountN);
			return;
		}
		}

		withdraw(head->next,accountN,amount);
	}


	void displayAccount(struct Node* head, int accountN){ //displays one account details given the account number
	
		if(head->accountNumber == accountN) {
			cout<<endl<<"Account number: "<<head->accountNumber
			<<endl;
			cout<<"Account balance: "<<head->balance
			<<endl;
			cout<<"Account type: "<<head->type
			<<endl<<endl;
			return;
		}
		displayAccount(head->next,accountN);

	}
	void displayAccounts(){ //displays all accounts related to a customer
		Node *temp = new Node;
		temp = head;

		if(temp==NULL){
			cout<<endl<<"No accounts to display."<<endl;
		} 

		while(temp != NULL) {
			cout<<endl<<"Account number: "<<temp->accountNumber
			<<endl;
			cout<<"Account balance: "<<temp->balance
			<<endl;
			cout<<"Account type: "<<temp->type
			<<endl;

			temp = temp -> next;
		}
	}

	

	void searchAccount(struct Node *head, int accountN){ //searches for an account given account number
		if(head == NULL){
			cout<<"Account not found."<<endl;
			return;
		}
		if(head -> accountNumber == accountN){
			cout<<"Found!"
			<<endl
			<<"Account number: "<<head -> accountNumber
			<<endl
			<<"Account balance: "<<head -> balance
			<<endl
			<<"Account type: "<<head -> type
			<<endl;
			return;
		}
		searchAccount(head->next,accountN);

	}
};


#endif