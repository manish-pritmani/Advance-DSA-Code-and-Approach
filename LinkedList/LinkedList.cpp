#include<iostream>
using namespace std;

// Node data type created
class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = nullptr;
	}
};

// Insertion at Beginning of Linked List.
void insertBegin(node* &head, int data){
	if(head == nullptr){
		head = new node(data);
		return;
	}
	node* i = new node(data);
	i->next = head;
	head = i;
}

// Print Linked List
void print(node* head){
	// Corner Case
	if(head == nullptr){
		return;
	}
	// Print Linked List
	while(head!=nullptr){
    if(head->next == nullptr){
      cout<<head->data;
    }else{
      cout<<head->data<<" -> ";
    }
		head = head->next;
	}
}

// Count Number of Nodes
int count(node* head){
	int cnt = 0;
	while(head!=nullptr){
		cnt++;
		head = head->next;
	}
	return cnt;
}

// Insert at Tail
void insertAtTail(node* &head, int data){
  if(head == nullptr){
    head = new node(data);
    return;
  }
  node* temp = head;
  while(temp->next!= nullptr){
    temp = temp->next;
  }
  temp -> next = new node(data);
  return;
}

void insertAtTail2(node* &head,int data){
  if(head == nullptr){
    head = new node(data);
    return;
  }
  int len = count(head);
  node* temp = head;
  // decrease before you enter loop.
  while(--len){
    temp=temp->next;
  }
  temp->next = new node(data);
  // return;
}

// Insert at particular position
void insertAtPosition(node* &head, int data,int position){
  int len = count(head);
  if(head == nullptr or position == 0){
    head = new node(data);
  } else if(position > len){
    insertAtTail(head,data);
  } else{
    node* temp = head;
    while(--position){
      temp= temp->next;
    }
    node* ins = new node(data);
    ins->next = temp->next;
    temp->next = ins; 
  }
}

// Delete Head of the Linked List.
void deleteAtHead(node* &head){
  if(head == nullptr){
    return;
  }
  node* temp = head->next;
  // delete node at that address, but head name will remain
  delete head;
  head = temp;
}

// Delete at any position.
void deleteAtPosition(node* &head,int position){
  if(head == nullptr){
    return;
  }
  else if(position == 0){
    deleteAtHead(head);
  }else{
    node* temp = head;
    node* prev = head;
    while(--position){
      prev = temp;
      temp = temp->next;
    }
    node* next = temp->next;
    prev->next = next;
    delete temp;
  }
}

// Search Element in Linked List.




// Reverse a Linked List
// Bad Approach 1 - swap first and last node then second and second last ..so on
node* reverseLinkedList(node* head){
 
}

// Main Function
int main(){
	node* head = nullptr;
	insertBegin(head,1);
	insertBegin(head,2);
	insertBegin(head,3);
	insertBegin(head,4);
  cout<<"Count : "<<count(head)<<endl;
  insertAtTail2(head,5);
  insertAtPosition(head,0,3);
  // deleteAtHead(head);
  // deleteAtPosition(head,3);
  print(head);
  cout<<endl;
  int key = 3;
  if(searchLink(head,key)){
    cout<<"Element Found";
  }else{
    cout<<"Not Found!";
  }
	return 0;
}

/* Notes Center - 
1. head will be of node* type.
2. new keyword return address of memory created dynamically.
3. (*n).next we call this derefrencing the pointer.
4. (*n).next and n->next is same.
5. while(head!=nullptr) after loop head will be null
   while(head->next!=nullptr) after loop head will be at last node.

  decide according to the purpose.
6. Deletion at head place is more efficient in Linked list as Array,       because in array shifting of data is O(n).


*/