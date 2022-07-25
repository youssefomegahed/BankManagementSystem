#ifndef BM_ACCOUNT_H
#define BM_ACCOUNT_H
#include "common.h"
#include "bm_customers.h"
#include "bm_account.h"

//forward declarations
struct Node;
class Customer;
class Account;

class Transactions : public Account, public Customer
{
	Node *head, *tail;

	Transactions(){
		head = NULL;
		tail = NULL;
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

};

#endif