#include <bits/stdc++.h>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};
class pairll{
	public:
	Node* head;
	Node* tail;
};

Node* takeInpu_Better() {
	int data,c=0;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}
        c++;
		cin >> data;
	}
	//cout<<c<<endl;
	return head;
}
Node* deletion(Node* head,int n){
	int i=0;
	if(n==0){
		Node* a=head;
		head=head -> next;
		delete a;
		return head;
	}
	Node* temp=head;
	while(i<n-1&&temp!=NULL){
		temp=temp -> next;
		i++;
		
	}
	if(temp==NULL)return head;
	if(temp -> next!=NULL){
	Node* a=temp -> next;
	temp -> next=(temp -> next)-> next;
	delete a;}
	return head;
	
}

void print(Node *head) {
	Node* temp=head;
	while(temp!=NULL) {
		cout<<temp -> data<<" ";
		temp = temp -> next;
	}
}
Node* insertion(Node* head,int i,Node* newnode){
	if(head==NULL){
		return head;
	}
	if(i==0){
		
		newnode -> next=head;
		head=newnode;
		
	}
	Node* x=insertion(head -> next,i-1,newnode);
	head -> next=x;
	
	
	return head;
}
Node* deletion_rr(Node* head,int i){
	if(head==NULL){
		return head;
	}
      if(i==0){
		Node* a=head;
		head=head -> next;
		delete a;
	}
	
     Node* x=deletion_rr(head -> next,i-1);
	 head -> next=x;
	
	return head;
}
int find_node(Node* head,int x){
    int count =0;
	while(head!=NULL){
    	if(head->data==x){
    		return count;
		}
		count++;
		head=head->next;
	}
	return -1;
}
int lengthll(Node* head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head -> next;
	}
	return count;
}
Node* appendlastntofirst(Node* head,int i){
	int ct=0;Node* temp=head;
	while(ct<i-1){
		ct++;temp=temp->next;
	}
	Node* head2=temp->next;
	temp->next=NULL;
	Node* tail=head2;
	while(tail->next!=NULL){
		tail=tail->next;
		
	}
	tail->next=head;
	head=head2;
	return head;
	
}
Node* eliminate_duplicates(Node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node* t1=head;
	Node* t2=head->next;
	while(t2!=NULL){
		if(t1->data==t2->data){
			t2=t2->next;
			continue;
		}
		else{
			t1->next=t2;
			t1=t2;
			t2=t2->next;
			
		}
		}t1->next=t2;
	
	return head;
}
void printreverse_ll(Node* head){
	if(head==NULL){
		return;
	}

	 printreverse_ll(head->next);
     cout<<head->data<<" ";
	
}

bool palindrome(Node* temp,int mid){
	vector<int>v1,v2;
	int c=0;
	while(c<mid){
		v1.push_back(temp->data);
		temp=temp->next;
		c++;
	}
	while(temp!=NULL){
		v2.push_back(temp->data);
		temp=temp->next;
	}
	reverse(v2.begin(),v2.end());
	for(int i=0;i<v2.size();i++){
		if(v1[i]!=v2[i])return false;
	}
   return true;
}
Node* mergetwosortedlinkedlist(Node* head1,Node* head2){
	Node* fhead=NULL;  Node* ftail=NULL;
	
	if((head1->data)<=(head2->data)){
		fhead=head1;
		ftail=head1;
		head1=head1->next;
	}
	else{
		fhead=head2;
		ftail=head2;
		head2=head2->next;
	}
	while(head1!=NULL&&head2!=NULL){
		if((head1->data)<=(head2->data)){
		ftail->next=head1;
		ftail=head1;
		head1=head1->next;
	}
	else{
		ftail->next=head2;
		ftail=head2;
		head2=head2->next;
	}
	}
     if(head1!=NULL){
     	ftail->next=head1;
	 }
	 else{
	 	ftail->next=head2;
	 	}
	return fhead;
	
	
}

Node* reversellrr(Node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node* a=reversellrr(head->next);
	Node* temp=a;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return a;
}
pairll reversellrr2(Node* head){
	if(head==NULL||head->next==NULL){
		pairll ans;
		ans.head=head;
		ans.tail=head;
		return ans;
	}
	pairll a=reversellrr2(head->next);
	a.tail->next=head;
	head->next=NULL;
	pairll ans;
	ans.head=a.head;
	ans.tail=head;
	return ans;
	
}

Node* reverseiterative(Node* head1){
	
	if(head1==NULL||head1->next==NULL){
		return head1;
	}
	Node* prev=NULL;
	Node* curr=head1;
	Node* ahead=head1->next;
	
	while(curr->next!=NULL){
		
		curr->next=prev;
		prev=curr;
		curr=ahead;
		ahead=ahead->next;
		
	}
	curr->next=prev;

	return curr;
	
}
find_rr(Node* head,int x){
	if(head==NULL){
		return -1;
	}
	if(head->data==x){
		return 0;
	}
	int c=find_rr(head->next,x);
	if(c==-1)return -1;
	else return c+1;
}
Node* deleteeverynnodes(Node* head,int x,int y){
	if(head==NULL||x==0){
		return NULL;
	}
	Node* a=head,*b,*temp=head,*ans=head;
	while(temp!=NULL){
	 int c1=0,c2=0;
	 while(c1<x-1&&a->next!=NULL){
	 	a=a->next;c1++;
	}b=a->next;
	while(c2<y&&b!=NULL)
	{   Node* d=b;
		b=b->next;
		delete d;
		c2++;
	}
	a->next=b;
	a=b;
	temp=b;	
}return ans; }

Node* swap_nodes(Node* head,int x,int y){
	if(x==y|head==NULL)
	{
		return head;
	}
	else if(x==0&&y!=0)
	{
		int c1=0;Node* temp=head,*a,*b;
		while(c1<y-1){c1++;
			temp=temp->next;
			}
			a=temp->next;
			temp->next=head;
			b=head->next;
			head->next=a->next;
			a->next=b;
			head=a;
			return head;
	}
	else {
		int c1=0,c2=0;Node* temp=head,*a=head,*b,*c;
		while(c1<x-1)
		{c1++;
			temp=temp->next;
		}
			while(c2<y-1)
			{c2++;
			a=a->next;
		}
		c=temp->next;
		b=a->next;
		a->next=c;
		temp->next=b;
		b=b->next;
		temp->next->next=c->next;
		c->next=b;
		return head;
	}
    
}
Node* kreverse(Node* head,int k){
	
	if(head==NULL||head->next==NULL)
	{
		return  head;
	}
	int c1=0;
	Node* temp=head;
	Node *b=head;
	
	while(c1<k-1&&temp->next!=NULL)
	{
		temp=temp->next;
		c1++;
	}
	
	Node* a=temp->next;
	temp->next=NULL;
	pairll y=reversellrr2(head);
	Node* x=kreverse(a,k);
	y.tail->next=x;
	return y.head;

	
}

Node* bubblesort(Node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	int c=lengthll(head),i;
	for(i=0;i<c;i++){
		Node* temp=head,*curr=head->next,*a=head;
	while(curr!=NULL)
	{  
	if((temp->data>curr->data)&&(temp==head)){
		temp->next=curr->next;
		curr->next=temp;
		head=curr;
		a=head; 
		curr=temp->next;
		
	}
	else if(temp->data>curr->data){
		 temp->next=curr->next;
		 a->next=curr;
		 curr->next=temp;
		 curr=temp->next;
	     a=a->next;
	}
	else{
		a=temp;
		temp=temp->next;
		curr=curr->next;
	}
		  	
	}}return head;
}


int main() {

	//Node *head1 = takeInpu_Better();
	//Node *head2 = takeInpu_Better();
	//int x,y;cin>>x>>y;
	//int k;cin>>k;
	//int c,i;cin>>i;
	//Node* fhead=mergetwosortedlinkedlist(head1,head2);
	//c=lengthll(head);
	//int ans=palindrome(head,(c+1)/2);
	//cout<<(ans?"true":"false");
	//Node* newnode= new Node(data);
	//head=appendlastntofirst(head,c-i);
	//head= eliminate_duplicates(head);
	//print(head);
	//int n;cin>>n;
	//head=deletion(head,n);
	//pairll ans=reversellrr2(head1);
	//print(ans.head);
	//Node* head=reverseiterative(head1);
	//cout<<find_rr(head1,x)<<endl;
	//Node* head=deleteeverynnodes(head1,x,y);
	//Node* head=swap_nodes(head1,x,y);
	//Node* head=bubblesort(head1);
	//kreverse(head1,k);
	//print(head);
	//printreverse_ll(head);
	return 0;
}

