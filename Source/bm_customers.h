#ifndef BM_CUSTOMERS_H
#define BM_CUSTOMERS_H
#include "common.h"

//forward declarations
struct Node 
{
//data
	int id, accountNumber;
	string mobile, home, emergency_contact, first_name, last_name ;
	string full_name = first_name + " " + last_name;
	char address[50], email[50];
	int balance;
	string type, card1, card2;

//pointer to the next node in the list
	Node* next;
};

class Customer
{

public:
	Node *head, *tail;
	
	Customer() {
	head = NULL;
	tail = NULL;
	}


	 void createCustomer(int integer) //creates a customer by asking user for information
	{
		Node *temp = new Node;
		temp -> id = integer;

		//user entered data
 		cout<<endl<<"First name: ";
 		cin >> temp -> first_name;
 		cout<<endl
 		<<"Last name: ";
 		cin >> temp -> last_name;
 		cout<<endl
 		<<"Address: ";
 	//	cin.get(temp->address,50);
 		cin >> temp -> address;
 		cout<<endl
 		<<"Mobile: ";
 		cin >> temp -> mobile;
 		cout<<endl
 		<<"Home telephone: ";
 		cin >> temp -> home;
 		cout<<endl
 		<<"E-mail: ";
 	//	cin.get(temp -> email, 50);
 		cin >> temp -> email;
 		cout<<endl
 		<<"Emergency contact (phone): ";
 		cin >> temp -> emergency_contact; 
 		cout<<endl
 		<<"Customer " << temp -> first_name << " " << temp -> last_name <<" has been created with ID "<<temp->id<<endl;
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


	bool checkID(struct Node* head, int x) //checks if entered ID already exists
	{ 
		Node *temp = head;
		
		if(head == NULL) return true;

		while(temp!=NULL){
		if(temp->id == x){
			cout<<"ID already exists, try again."<<endl;
			return false;
		}
		temp = temp->next;
		}
		return true;
	}


	void searchbyID(struct Node* head, int x) //searches for customer given an ID
	{ 
		if(head == NULL) {
		cout<<"Customer not found"<<endl; //case ID does not exist
		return;
		}	

		if (head -> id == x) {
			cout<<endl<<"Found!"<<endl;
			cout<<"Name: "<<head->first_name <<" "<<head -> last_name<<endl;
			cout<<"ID: "<<head->id<<endl;
		/*	cout<<"Mobile: "<<head->mobile<<endl;
			cout<<"Home telephone: "<<head->home<<endl;
			cout<<"Address: "<<head->address<<endl;
			cout<<"E-mail: "<<head->email<<endl;
			cout<<"Emergency Contact: "<<head->emergency_contact<<endl; */
			return;
		}

		searchbyID(head->next, x); //recursion
	}



	void searchbyName(struct Node* head, string first, string last) //searches for customer given first name, second name, or both
	{ 
		if(head == NULL) {
			cout<<"--results of your search are displayed above--"<<endl;
			return;
		}

		if(head -> first_name == first && head -> last_name == last) {
			cout<<endl<<"Found!"<<endl;
			cout<<"Name: "<<head->first_name <<" "<<head -> last_name<<endl;
			cout<<"ID: "<<head->id<<endl;
		/*	cout<<"Mobile: "<<head->mobile<<endl;
			cout<<"Home telephone: "<<head->home<<endl;
			cout<<"Address: "<<head->address<<endl;
			cout<<"E-mail: "<<head->email<<endl;
			cout<<"Emergency Contact: "<<head->emergency_contact<<endl<<endl; */
				
		
		} else if(head->first_name == first && head->last_name != last) {
			cout<<endl<<"Found!"<<endl;
			cout<<"Name: "<<head->first_name <<" "<<head -> last_name<<endl;
			cout<<"ID: "<<head->id<<endl;
		/*	cout<<"Mobile: "<<head->mobile<<endl;
			cout<<"Home telephone: "<<head->home<<endl;
			cout<<"Address: "<<head->address<<endl;
			cout<<"E-mail: "<<head->email<<endl;
			cout<<"Emergency Contact: "<<head->emergency_contact<<endl<<endl; */
		

		} else if(head->first_name != first && head->last_name == last) {
			cout<<endl<<"Found!"<<endl;
			cout<<"Name: "<<head->first_name <<" "<<head -> last_name<<endl;
			cout<<"ID: "<<head->id<<endl;;
		/*	cout<<"Mobile: "<<head->mobile<<endl;
			cout<<"Home telephone: "<<head->home<<endl;
			cout<<"Address: "<<head->address<<endl;
			cout<<"E-mail: "<<head->email<<endl;
			cout<<"Emergency Contact: "<<head->emergency_contact<<endl<<endl; */
		}

		searchbyName(head->next, first, last);
	}


	int nameToID(string first, string last) //function that returns ID when given first and last names
	{
		Node *temp = new Node;
		temp = head;

		while(temp != NULL){
			if(first == temp->first_name || last == temp->last_name){
				return temp->id;
			}
			temp = temp->next;
		}
	}


	void displayInfo(struct Node* head, int x) //displays all information available on a customer
	{ 
		
		if (head -> id == x) {
			cout<<endl<<"Name: "<<head->first_name <<" "<<head -> last_name<<endl;
			cout<<"ID: "<<head->id<<endl;
			cout<<"Mobile: "<<head->mobile<<endl;
			cout<<"Home telephone: "<<head->home<<endl;
			cout<<"Address: "<<head->address<<endl;
			cout<<"E-mail: "<<head->email<<endl;
			cout<<"Emergency Contact: "<<head->emergency_contact<<endl<<endl; 
			return;
		}
		displayInfo(head->next, x); //recursion
		}



	void deleteCustomer(struct Node **head_ref, int key) //deletes a customer
	{
		struct Node *temp = *head_ref, *prev;
		if(temp != NULL && temp->id == key)
		{
			*head_ref = temp->next;
			free(temp);
			return;
		}
		while(temp != NULL && temp->id != key){
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL)
			return;

		prev -> next = temp -> next;
		free(temp);

	}

	
	void deleteDuplicate() //extra. could be used to ensure IDs aren't repeated
	{
		Node *ptr1, *ptr2, *duplicate;
		ptr1 = head;

		while(ptr2->next != NULL)
		{
			if(ptr1->id == ptr2->next->id) {
				duplicate = ptr2 -> next;
				ptr2->next = ptr2->next->next;
				delete(duplicate);
			} else {
				ptr2 = ptr2 -> next;
			}
			ptr1=ptr1->next;
		}
	}

	void displayAll() //displays all available customers
	{ 
		Node *temp = new Node;
		temp = head;

		if(temp == NULL){
			cout<<endl<<"No customers to display."<<endl;
		}
		while(temp != NULL){
			cout<<endl<<"ID: "<<temp->id<<endl;
			cout<<"Name: "<<temp->first_name <<" "<<temp->last_name<<endl;
	/*		cout<<"Mobile: "<<temp->mobile<<endl;
			cout<<"Home telephone: "<<temp->home<<endl;
			cout<<"Address: "<<temp->address<<endl;
			cout<<"E-mail: "<<temp->email<<endl;
			cout<<"Emergency Contact: "<<temp->emergency_contact<<endl<<endl<<endl; */

			temp = temp -> next;
		}
	}

	
};


#endif
