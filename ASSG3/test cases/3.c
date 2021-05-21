#include<stdio.h>
#include<stdlib.h>

typedef struct rb{
	int key;
	char color;
	struct rb *left,*right;
}*node;

node NIL;

node create()
{
	node temp = (node)malloc(sizeof(struct rb));
	temp->left = NIL;
	temp->right = NIL;
	temp->color = 'R';
	return temp;
}

node rightrotate(node x)
{
	node y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

node leftrotate(node x)
{
	node y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

node insert(node r,node x)
{
	if(r==NIL)
		return x;
	else if(r->key>x->key)
	{
		r->left = insert(r->left,x);
		if(r->left->color=='R')
		{
			if(r->left->left->color=='R'||r->left->right->color=='R')
			{	
				if(r->right->color=='R')
				{
					r->right->color='B';
					r->left->color='B';
					r->color='R';
				}
				else
				{
					if(r->left->left->color=='R')
					{
						node y=rightrotate(r);
						y->right->color='R';
						y->color='B';
						return y;
					}
					else
					{
						r->left = leftrotate(r->left);
						node y = rightrotate(r);
						y->right->color='R';
						y->color='B';
						return y;
					}
				}
			}
		}
		return r;
	}
	else
	{
		r->right = insert(r->right,x);
		if(r->right->color=='R')
		{
			if(r->right->left->color=='R'||r->right->right->color=='R')
			{
				if(r->left->color=='R')
				{
					r->left->color='B';
					r->right->color='B';
					r->color='R';
				}
				else
				{
					if(r->right->right->color=='R')
					{
						node y = leftrotate(r);
						y->left->color='R';
						y->color='B';
						return y;
					}
					else
					{
						r->right = rightrotate(r->right);
						node y = leftrotate(r);
						y->left->color='R';
						y->color = 'B';
						return y;
					}
				}
			}
		}
		return r;
	}
}

node rbinsert(node r,node x)
{
	r = insert(r,x);
	if(r->color=='R')
		r->color = 'B';
	return r;
}

node printTree(node A)
{
        if(A!=NIL)
        {
                printf("( %d %c ",A->key,A->color);
                printTree(A->left);
                printTree(A->right);
                printf(") ");
                return A;
        }
        else
        {
                printf("( ) ");
                return A;
        }
}

int main()
{
        NIL = (node)malloc(sizeof(struct rb));
        NIL->left=NULL;
        NIL->right=NULL;
        NIL->color='B';
        node tree=NIL;
	int i;
	while(scanf("%d",&i)==1)
	{
		node x = create();
		x->key = i;
		tree = rbinsert(tree,x);
		printTree(tree);
		printf("\n");
	}
}
