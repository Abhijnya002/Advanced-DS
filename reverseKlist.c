#include <iostream>
 
using namespace std; 
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE insert_front(int item,NODE head);
NODE reverseKNodes (NODE head, int k);
int main()
{
	NODE head=NULL;
	int n,ele,p,i,k;
	cout<<"Enter 1 to insert ele,2 to reverse the list,3 to display=";
	cin>>n;
	while(n!=0)
	{
	switch(n)
	{
		case 1:cout<<"enter the ele=\n";
	 		cin>>ele;
			head=insert_front(ele,head);
			break;
		case 2:cout<<"enter the K=\n";
	 		cin>>k;
			head=reverseKNodes (head,k);
			break;
		case 3:display(head);
			break;
		
	}
	cout<<"again enter choice=\n"<<" ";
	cin>>n;
}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		cout<<"list is empty\n";
		exit(0);
	}
	p=head;
    cout<<"contents of list=\n";
	while(p!=NULL)
	{
		cout<<p->data<<"\n ";
		p=p->next;
	}
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
		cout<<"Memory couldnt be allocated";
		exit(0);
}
NODE reverse(NODE head)
{
	NODE curr=head,prev =NULL,nextn=NULL;
	if(head==NULL)
	{
		cout<<"list is empty\n";
		return head;
	}
	if(head->next==NULL)
	{
		return head;
	}
	while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
	}
	head=prev;
	return head;
}
NODE reverseKNodes (NODE head, int k)
{
    NODE q = head;
    NODE r = NULL;
    NODE s;
    int count = 0;
     
    while (q != NULL && count < k)
    {
       s = r;
       r = q;
       q  = q->next;
       r->next = s;
       count++;
    }
      
    if(q !=  NULL)
         head->next = reverseKNodes(q, k);
  
    return r;
}
