#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define maxn 100000
#define ll int
#define INF ll_MAX

struct node_fib {
	int val;
	int dgr;
	struct node_fib * parent;
	struct node_fib * child;
	struct node_fib * left;
	struct node_fib * right;
	int clr;
	int flag;
};

struct node_fib * fib_heap = NULL;
ll number = 0;

struct node_fib *create_node(ll x)
{
	struct node_fib *make_node = (struct node_fib *)malloc(sizeof (struct node_fib));
	make_node->parent = NULL;
	make_node->child = NULL;
	make_node->left = NULL;
	make_node->right = NULL;
	make_node->val = x;
	make_node->dgr = 0;
	make_node->clr = 0;
	make_node->flag = 0;
	return make_node;
}

void fib_insert(ll x)
{
	struct node_fib * make_node = create_node(x);
	make_node->left = make_node;
	make_node->right = make_node;
	if (fib_heap != NULL)
	{
		(fib_heap->left)->right = make_node;
		make_node->right = fib_heap;
		make_node->left = fib_heap->left;
		fib_heap->left = make_node;
		if (make_node->val < fib_heap->val)
			fib_heap = make_node;
	}
	else fib_heap = make_node;
	number++;
	return ;
}

void fib_link(struct node_fib * tree1, struct node_fib *tree2)
{
	(tree1->left)->right = tree1->right;
	(tree1->right)->left = tree1->left;
	if (tree2->right == tree2)
		fib_heap = tree2;
	tree1->left = tree1;
	tree1->right = tree1;
	tree1->parent = tree2;
	if (tree2->child == NULL)
		tree2->child = tree1;
	tree1->right = tree2->child;
	tree1->left = (tree2->child)->left;
	((tree2->child)->left)->right = tree1;
	(tree2->child)->left = tree1;
	if (tree1->val < (tree2->child)->val)
		tree2->child = tree1;
	tree2->dgr++;
	return  ;
}
unsigned int lg(unsigned int n)
{
    return (n > 1) ? 1 + lg(n / 2) : 0;
}
 

void consolidate()
{
	float fl = (float)((lg((float)number)) / (log((float)2)));
	ll sz = fl;
	struct node_fib * vec[sz + 1];
	for (ll i = 0; i < sz + 1; i++)
		vec[i] = NULL;
	struct node_fib * fib1 = fib_heap;
	struct node_fib * fib2 = NULL;
	struct node_fib * fib3 = NULL;
	struct node_fib * fib4 = fib1;
	do {
		fib4 = fib4->right;
		ll x1 = fib1->dgr;
		while (vec[x1] != NULL) {
			fib2 = vec[x1];
			if (fib1->val > fib2->val) {
				fib3 = fib1;
				fib1 = fib2;
				fib2 = fib3;
			}
			if (fib2 == fib_heap)
				fib_heap = fib1;
			fib_link(fib2, fib1);
			if (fib1->right == fib1)
				fib_heap = fib1;
			vec[x1] = NULL;
			x1++;
		}
		vec[x1] = fib1;
		fib1 = fib1->right;
	} while (fib1 != fib_heap);
	fib_heap = NULL;
	for (ll j = 0; j <= sz; j++) {
		if (vec[j] != NULL) {
			vec[j]->left = vec[j];
			vec[j]->right = vec[j];
			if (fib_heap != NULL) {
				(fib_heap->left)->right = vec[j];
				vec[j]->right = fib_heap;
				vec[j]->left = fib_heap->left;
				fib_heap->left = vec[j];
				if (vec[j]->val < fib_heap->val)
					fib_heap = vec[j];
			}
			else {
				fib_heap = vec[j];
			}
			if (fib_heap == NULL)
				fib_heap = vec[j];
			else if (vec[j]->val < fib_heap->val)
				fib_heap = vec[j];
		}
	}
	return ;
}

void extract_min()
{
	if (fib_heap != NULL)
	{
		struct node_fib * fib = fib_heap;
		struct node_fib * vis = fib;
		struct node_fib * jkl = NULL;
		if (fib->child != NULL) {

			jkl = fib->child;
			do {
				vis = jkl->right;
				(fib_heap->left)->right = jkl;
				jkl->right = fib_heap;
				jkl->left = fib_heap->left;
				fib_heap->left = jkl;
				if (jkl->val < fib_heap->val)
					fib_heap = jkl;
				jkl->parent = NULL;
				jkl = vis;
			} while (vis != fib->child);
		}
		(fib->left)->right = fib->right;
		(fib->right)->left = fib->left;
		fib_heap = fib->right;
		if (fib == fib->right && fib->child == NULL)
			fib_heap = NULL;
		else {
			fib_heap = fib->right;
			consolidate();
		}
		number--;
	}
	return;
}

void break_point(struct node_fib * detect, struct node_fib * fib)
{
	if (detect == detect->right)
		fib->child = NULL;
	(detect->left)->right = detect->right;
	(detect->right)->left = detect->left;
	if (detect == fib->child)
		fib->child = detect->right;
	(fib->dgr)--;
	detect->left = detect;
	detect->right = detect;
	(fib_heap->left)->right = detect;
	detect->left = fib_heap->left;
	detect->right = fib_heap;
	fib_heap->left = detect;
	detect->clr = 1;
	detect->parent = NULL;
	return;
}

void recur_break(struct node_fib * fib)
{
	struct node_fib * mix = fib->parent;
	if (mix != NULL) {
		if (fib->clr == 0) {
			fib->clr = 1;
		}
		else {
			break_point(fib, mix);
			recur_break(mix);
		}
	}
	return ;
}

void Decrease_val(struct node_fib * detect, ll val)
{
	if (fib_heap != NULL && detect != NULL)
	{
		detect->val = val;
		struct node_fib * fib = detect->parent;
		if (fib != NULL && detect->val < fib->val) {
			break_point(detect, fib);
			recur_break(fib);
		}
		if (detect->val < fib_heap->val)
			fib_heap = detect;
	}
	return;
}

void search(struct node_fib * fib_heap, int initial, int final)
{
	struct node_fib * detect = NULL;
	struct node_fib * fib5 = fib_heap;
	fib5->flag = 1;
	struct node_fib * detect_ptr = NULL;
	if (fib5->val == initial) {
		detect_ptr = fib5;
		fib5->flag = 0;
		detect = detect_ptr;
		Decrease_val(detect, final);
	}
	if (detect_ptr == NULL) {
		if (fib5->child != NULL)
			search(fib5->child, initial, final);
		if ((fib5->right)->flag != 1)
			search(fib5->right, initial, final);
	}
	fib5->flag = 0;
	detect = detect_ptr;
	return ;
}

void dlt_fib(ll x)
{
	if (fib_heap != NULL)
	{
		search(fib_heap, x, 0);
		extract_min();
	}
	return ;
}

void display()
{
	struct node_fib * curr = fib_heap;
	if (curr != NULL)
	{
		do {
			printf("%d ", curr->val);
			curr = curr->right;
		} while (curr != fib_heap && curr->right != NULL);
	}
	return ;
}

int main()
{
	char ch;
	int w=0;
	while (w<1)
	{
		scanf("%c", &ch);
		switch(ch){
		case 'i':int x; scanf("%d", &x);
			 INSERT(x);
		         break;
		case 'm':if (mini != NULL)
			 printf("%d\n", mini->val);
		         break;
		case 'x':if (mini != NULL)
			printf("%d\n", mini->val);
			extract_min();
			break;
		case 'r':int y, z;
			scanf("%d", &y);
			scanf("%d", &z);
			FIND(mini, y, z);
			printf("%d\n", z);
		        break;
		case 'd':int x; scanf("%d", &x);
			printf("%d\n", x);
			dlt_fib(x);
			break;
		case 'p':display();
			printf("\n");
			break;
		case 'e': w++;}
	}
	return 0;
}
