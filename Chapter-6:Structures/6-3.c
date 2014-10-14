#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"getword.h" /*assuming there is a file getword.h in current dir */
#define MAXWORD 100
struct linklist {
	int lnum;
	struct linklist *ptr;
};
struct tnode {
	char *word;						//points to words
	struct linklist *lines;			// line numbers
	struct tnode *left;				//left child
	struct tnode *right;			//right child
};
/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}
/* lalloc: make a linklist node */
struct linklist *lalloc(void)
{
	return (struct linklist *)malloc(sizeof(struct linklist));
}

/* addline : add line numbers to linked list lines */
void addline(struct tnode *p, int linenum)
{
	struct linklist *temp;
	temp = p->lines;
	while(temp->ptr != NULL && temp->lnum != linenum)
		temp = temp->ptr;
	if (temp->lnum != linenum) {
		temp->ptr = lalloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr= NULL;
	}
}
/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum)
{
  int cond;
  if(p == NULL) {  /* a new word has arrived */
      p = talloc();  /* make a new node */
      p->word = strdup(w);
      p->lines = lalloc();  /* make a new space for linenumbers*/
      p->lines->lnum = linenum; 
      p->lines->ptr = NULL;
      p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
      addline(p, linenum);
  else if( cond < 0)
      p->left = addtreex(p->left, w, linenum);
  else if(cond > 0)
      p->right = addtreex(p->right, w, linenum);
  return p;
}
/* treexprint: in-order print of tree p  */
void treexprint(struct tnode *p)
{
	struct linklist *tmp;
	if(p != NULL) {
		treexprint(p->left);
		printf("%10s: ", p->word);
		for ( tmp = p->lines; tmp != NULL; tmp = tmp->ptr)
			printf("%4d ",tmp->lnum);
		printf("\n");
		treexprint(p->right);
	}
}
/* noiseword: identify word as a noise word */
int noiseword(char *w)
{
	static char *nw[] = {
			"a",
			"an",
			"and",
			"be",
			"but",
			"by",
			"he",
			"I",
			"is",
			"it",
			"off",
			"or",
			"so",
			"that",
			"the",
			"they",
			"to"
	};
	int cond, mid;
	int low = 0;
	int high = sizeof(nw) / sizeof(char*) - 1;
	while(low <= high) {
		mid = (low + high) /2;
		if((cond = strcmp(w, nw[mid])) < 0)
			high = mid -1;
		else if(cond > 0)
			low = mid +1;
		else return mid;
	}
	return -1;
}
/* cross referencer */
main()
{
	struct tnode *root;
	char word[MAXWORD];
	int linenum = 1;
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && noiseword(word) == -1)
			root = addtreex(root, word, linenum);
		else if(word[0] == '\n')
			linenum++;
	treexprint(root);
	return 0;
}

