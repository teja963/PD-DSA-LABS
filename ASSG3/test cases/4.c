#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int  max=100000;
struct node{
	int val;
	int deg;
	struct node *p;
	struct node *sibling;
	struct node *child;
};

struct queue{
	struct node *head;
	struct queue *next;
};

typedef struct queue queue;
typedef struct node node;

queue *q=NULL;

void swap(int *x,int *y){
int k=*x;
*x=*y;
*y=k;
}
void DEQUEUE() {
	if(q==NULL) {
		return ;
	}
	queue *temp=q;
	q=q->next;
	free(temp);
}

void ENQUEUE(node *val) {
	queue *newnode=(queue *)malloc(sizeof(struct queue));
	newnode->head=val;
	newnode->next=NULL;
	if(q==NULL) {
		q=newnode;
		return ;
	}
	queue *temp=q;
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=newnode;
}




node* CREATE(int k) {
	node *newnode=(node *)malloc(sizeof(struct node));
	newnode->deg=0;
	newnode->val=k;
	newnode->sibling=NULL;
	newnode->child=NULL;
	newnode->p=NULL;
	return newnode;
}


node* MERGE(node *h1,node *h2) {
	node *h;
	node *temp;
	if(h1==NULL)
	return h2;
	if(h2==NULL)
	return h1;
	if(h1->deg<=h2->deg) {
		h=h1;
		h1=h1->sibling;
	}
	else {
		h=h2;
		h2=h2->sibling;
	}
	temp=h;
	while(h1!=NULL&&h2!=NULL) {
		if(h1->deg<=h2->deg) {
			temp->sibling=h1;
			temp=h1;
			h1=h1->sibling;
		}
		else {
			temp->sibling=h2;
			temp=h2;
			h2=h2->sibling;
		}
	}
	if(h1!=NULL) {
		temp->sibling=h1;
	}
	if(h2!=NULL) {
		temp->sibling=h2;
	}
	return h;
}

node* binomiallink(node *x,node *y) {
       if(x->val>y->val)swap(&x->val,&y->val);
	y->p=x;
	y->sibling=x->child;
	x->child=y;
	x->deg++;
	return x;
}


node* correcting(node *h) {
	node *x=NULL;
	node *p_x=NULL;
	node *n_x=NULL;
	if(h==NULL||h->sibling==NULL)
	return h;
	x=h;
	n_x=x->sibling;
	while(n_x!=NULL) {
																																																																																																																																											if(x->deg!=n_x->deg||(n_x->sibling!=NULL&&x->deg==n_x->sibling->deg)) {
																																																																																																																																												p_x=x;
																																																																																																																																												x=n_x;
																																																																																																																																												n_x=n_x->sibling;
																																																																																																																																											}
		else {
			if(x->val<=n_x->val) {
				x->sibling=n_x->sibling;
				binomiallink(x,n_x);
			}
			else {
				if(p_x==NULL) {
					h=n_x;
				}
				else {
					p_x->sibling=n_x;
				}
				binomiallink(n_x,x);
				x=n_x;
			}
			n_x=x->sibling;
		}
	}
	return h;
}



node* INSERT(node *h,int k) {
	node *temp=CREATE(k);
	h=MERGE(h,temp);
	return correcting(h);
}
node* reverselist(node *root) {
	node *p_x=NULL,*n_x=NULL,*x=NULL;
	if(root==NULL)
	return x;
	x=root;
	x->p=NULL;
	while(x!=NULL) {
		x->p=NULL;
		n_x=x->sibling;
		x->sibling=p_x;
		p_x=x;
		x=n_x;
	}
	return p_x;
}
node* extractmin(node *h) {

	node *temp1=NULL,*temp2=NULL;
	if(h==NULL)
	return temp1;
	node *x=h;
	node *p_x=NULL;
	temp1=x;
	int min=h->val;
	while(x!=NULL) {
		if(x->val<min) {
			min=x->val;
			temp1=x;
			temp2=p_x;
		}
		p_x=x;
		x=x->sibling;
	}
	if(temp2==NULL) {
		h=temp1->sibling;
	}
	else {
		temp2->sibling=temp1->sibling;
	}
	node *h2=reverselist(temp1->child);
	h=MERGE(h,h2);
	return correcting(h);
}


node* findnode(node* root, int k) {
   struct node* x = root;
   if(x==NULL)return x;
   else{
    struct node* p = NULL;
    if (x->val == k) {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL) {
        p = findnode(x->child, k);
    }
 
    if (x->sibling != NULL && p == NULL) {
        p = findnode(x->sibling, k);
    }
    return p;
}}

node* decreasekey(node *h,int x,int k) {

	if(h==NULL) {
		return h;
	}
	node *p=findnode(h,x);

	p->val-=k;
	node *p_pt=p->p;
	while(p_pt!=NULL&&p_pt->val>p->val) {
		int temp=p->val;
		p->val=p_pt->val;
		p_pt->val=temp;
		p=p_pt;
		p_pt=p->p;
	}

	return h;
}


void leveltraversal(node *root) {
	if(root==NULL)
	return ;
	ENQUEUE(root);
	while(q!=NULL) {
		printf("%d ",q->head->val);
		node *temp=q->head->child;
		while(temp!=NULL) {
			ENQUEUE(temp);
			temp=temp->sibling;
		}
		DEQUEUE();
	}
}

int minvalue(node *root) {
	if(root==NULL)return 0;
	int min=root->val;
	while(root) {
		if(root->val<min) {
			min=root->val;
		}
		root=root->sibling;
	}
	return min;
}

int DISPLAY(struct node* H) {
    struct node* p;
    if (H == NULL) {
        return 0;
    }
    p = H;
    while (p != NULL) {
        leveltraversal(p);
        p = p->sibling;
    }
    printf("\n");
}

node* deletekey(node *h,int k) {
	if(h==NULL){
		return h;
	}
	h=decreasekey(h,k,max);
	h=extractmin(h);
	return h;
}


int main() {
	int j,k,i,x,w=0;
	node *h=NULL,*temp=NULL;
	char c;
	while(w<1) {
		scanf("%c",&c);
		switch(c) {
			case 'i':
				scanf("%d",&k);
				h=INSERT(h,k);
				break;
			case 'p':
				DISPLAY(h);
				break;
			case 'x':
				i=minvalue(h);
				printf("%d\n",i);
				h=extractmin(h);
				break;
			
			case 'r':
				scanf("%d %d",&x,&k);
				temp=findnode(h,x);
				if(x>=k&&temp!=NULL) {
					h=decreasekey(h,x,k);
					printf("%d\n",x-k);
				}
				else
				printf("-1\n");
				break;
			case 'd':
				scanf("%d",&k);
				if(!findnode(h,k)) {
					printf("-1\n");
				}
				else {
					h=deletekey(h,k);
				} 
				break;
			case 'm':
				i=minvalue(h);
				printf("%d\n",i);
				break;
			case 'e':w++;
				
		}
	}
	
	return 0;
}


