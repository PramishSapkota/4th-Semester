// program for singly linked list
#include <iostream> 
using namespace std; 

class Node {//represents a node
 private: 
	int data; 
	Node* next; 
 public:
	Node() 
	{ 
		data = 0; 
		next = NULL; 
	} 
    
	Node(int data) 
	{ 
		this->data = data; 
		this->next = NULL; 
	} 
}; 
// implementing a linked list. 
class Linkedlist { 
	Node* head; 

 public: 
	Linkedlist() { head = NULL; } 
	void insert_1st(int);//to insert node at 1st position
	void insertNode(int); //to insert node
	void delete_1st();
	void deleteLast();//to delete last node
	void deleteNode(int);//to delete node at a position
		
	void printList(){
		Node* temp = head; 
		// Check for empty list. 
		if (head == NULL) { 
			cout << "List empty" << endl; 
			return;//bcz its void type the return 
		} 		 //statement will exit this function
		// Traverse the list
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->next; 
		} 
	} 
    // Destructor to release memory when the object is destroyed
	~Linkedlist(){
        Node* current = head;
        Node* next;
		while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
}; 
// delete node at given position 
void Linkedlist::deleteNode(int nodeOffset) 
{ 
	Node *temp1 = head, *temp2 = NULL; 
	int ListLen = 0; 

	if (head == NULL) { 
		cout << "List empty" << endl; 
		return; 
	} 

	// Find length of the linked-list. 
	while (temp1 != NULL) { 
		temp1 = temp1->next; 
		ListLen++; 
	} 
	if (ListLen < nodeOffset) { 
		cout << "Index out of range"<< endl; 
		return; 
	} 

	// Declare temp1 
	temp1 = head; 

	// Deleting the head. 
	if (nodeOffset == 1) { 

		// Update head 
		head = head->next; 
		delete temp1; 
		return; 
	} 

	// Traverse the list to find the node to be deleted. 
	while (nodeOffset-- > 1) { 

		// Update temp2 
		temp2 = temp1; 

		// Update temp1 
		temp1 = temp1->next; 
	} 

	// Change the next pointer of the previous node.
	temp2->next = temp1->next; 

	// Delete the node 
	delete temp1; 
} 

// Function to insert a new node. 
void Linkedlist::insertNode(int data) 
{ 
	// Create the new Node. 
	Node* newNode = new Node(data); 

	// Assign to head 
	if (head == NULL) { 
		head = newNode; 
		return; 
	} 

	// Traverse till end of list 
	Node* temp = head; 
	while (temp->next != NULL) {  
		temp = temp->next; 
	} 
	// Insert at the last. 
	temp->next = newNode; 
} 

int main() 
{ 
	Linkedlist list;
	int choice,a=1,value;
	do{
		cout<<"\n\n1:Insert node";
		cout<<"\n2:Insert node at 1st";
		cout<<"\n3:Delete node at given position";
		cout<<"\n4:Delete 1st node";
		cout<<"\n5:Delete last node";
		cout<<"\n6:Print Node";
		cout<<"\n7:Exit";
		here:
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		switch (choice){
		case 1:
			cout<<"\nEnter the data:";
			cin>>value;
			list.insertNode(value);
			break;

		case 2:
			cout<<"\nEnter the data:";
			cin>>value;
			list.insert_1st(value);
			break;

		case 3:
			cout<<"\nEnter the position:";
			cin>>value;
			list.deleteNode(value);
			break;
		case 4:
			list.delete_1st();
			break;

		case 5:
			list.deleteLast();
			break;

		case 6:
			cout<<"\nElements of list are:\n";
			list.printList();
			break;
		case 7:
			a=0;
			break;
		default:
			cout<<"Invalid input.Try again";
			goto here;
			break;
		}
	}while(a);

	return 0; 
}

void Linkedlist::insert_1st(int data){
	Node* newNode = new Node(data); 
	if (head == NULL) 
		head = newNode; 
	else{
		newNode->next=head;
		head=newNode;
	}
}

void Linkedlist::delete_1st(){
	Node *temp=head;
	head = head->next; 
	delete temp; 
}

void Linkedlist::deleteLast(){
	Node *temp1=head,*temp=NULL;
	while (temp1->next->next!= NULL) 
		temp1 = temp1->next; 
	temp=temp1->next;
	temp1->next=NULL;
	delete temp;
	
}