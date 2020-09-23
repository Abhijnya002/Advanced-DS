#include <iostream> 
#include <inttypes.h>  
using namespace std; 
  


class Node  
{  
    public: 
    int data;  
    Node* next; 
};  
  


Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
  

void insert_front(int data,Node **head)  
{  
   
    Node *new_node = new Node();  
    new_node->data = data;  
    new_node->next = *head;  
  
    if (*head != NULL)  
    {  

        (*head)->next = XOR(new_node, (*head)->next);  
    }  
  
    *head = new_node;  
}  
  
void insert_end(int data,Node **head)
{
    Node *new_node = new Node();
    new_node->data=data;
    Node *curr = *head;  
    Node *prev = NULL;  
    Node *p;
     while (XOR(prev,curr->next)!= NULL)  
    {  
             
        p = XOR (prev, curr->next);  
        prev = curr;  
        curr = p;  
    }
    new_node->next=curr;
    curr->next=XOR(prev,new_node);
    
}

void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *p;  
  
    cout << "Nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {  
        
        cout<<curr->data<<"\n";  
        p = XOR (prev, curr->next);  
        prev = curr;  
        curr = p;  
    }  
}  
  

int main ()  
{  
    int ch,ele;
    Node *head = NULL; 
    cout<<"Enter 1 to insert at the front,2 to insert at the end,3 to display=";
	cin>>ch;
	while(ch!=0)
	{
	    switch(ch)
	    {
		    case 1:cout<<"enter the ele=\n";
	 		    cin>>ele;
			    insert_front(ele,&head);
			    break;
			case 2:cout<<"enter the ele=\n";
	 		    cin>>ele;
			    insert_end(ele,&head);
			    break;
			case 3: printList (head);  
		    default:	break;
	    }
	cout<<"again Enter 1 to insert at the front,2 to insert at the end,3 to display=";
	cin>>ch;
	}
    return (0);  
}  