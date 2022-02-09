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

// Search Element in Linked List - O(n)
// Even if Linked List is sorted finding the length for middle will take O(n) time.
bool searchLink(node* head,int key){
  if(head == nullptr){
    return false;
  }
  
}



// Reverse a Linked List
// Bad Approach 1 - swap first and last node then second and second last ..so on
node* reverseLinkedList(node* &head){
  node* prev = nullptr;
  node* next = head->next;
  node* curr = head;
  while(curr!=nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

node* reverseRecr(node* head){
  if(head->next == nullptr || head == nullptr){
    return head;
  }
  // reversed Link List here
  node* sHead = reverseRecr(head->next);
  head->next->next = head;
  head->next = nullptr;
  return sHead;  
}

// Move last element to front of given linked list.
void moveLastToFront(node* &head){
  node* prev = head;
  node* curr = head;
  if(head == nullptr or head->next == nullptr){
    return;    
  }
  while(curr->next!=nullptr){
    prev = curr;
    curr = curr->next;
  }
  prev->next = nullptr;
  curr->next = head;
  head = curr;
}

// Intersection of two sorted linked list.
node* findIntersection(node* head1, node* head2) {
    if(head1== nullptr or head2 == nullptr){
        return nullptr;
    }
    node* tmp1 = head1;
    node* tmp2 = head2;
    node* dummy = new node(-1);
    node* ans = dummy; //p3
    node* a = dummy;   //p4
    while(tmp1!=nullptr and tmp2!=nullptr){
        if(tmp1->data == tmp2->data){
            a->next = tmp1;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            a=a->next;
        }
        else if(tmp1->data>tmp2->data){
            tmp2 = tmp2->next;     
        }
        else if (tmp1->data<tmp2->data){
            tmp1 = tmp1->next;
        }
    }
    return ans->next;
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
    cout<<"Element Found"<<endl;
  }else{
    cout<<"Not Found!";
  }
  reverseLinkedList(head);
  print(head);
  cout<<endl;
  moveLastToFront(head);
  print(head);
  head = reverseRecr(head);
  cout<<"\nRev "<<endl;
  print(head);
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