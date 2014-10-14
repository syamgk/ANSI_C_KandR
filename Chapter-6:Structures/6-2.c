#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"getword.h"
#define MAXWORD 100
#define YES 1
#define NO 0
struct tnode {
	char *word;			//points to words
	int match;			// match found
	struct tnode *left;	//left child
	struct tnode *right;//right child
};
/* compare: compare words and update p->match  */
int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p->word;
	for(i = 0; *s == *t; i++, s++,t++)
		if(*s == '\0')
			return 0;
	if(i >= num) {	/*identical in first num chars */
		*found = YES;
		p->match = YES;
	}
	return *s-*t;
}
/* talloc : make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
  int cond;
  if(p == NULL) {  /* a new word has arrived */
      p = talloc();  /* make a new node */
      p->word = strdup(w);
      p->match = *found;
      p->left = p->right = NULL;
  } else if ((cond = compare(w, p, num, found)) < 0)
      p->left = addtreex(p->left, w, num, found);
  else if(cond > 0)
      p->right = addtreex(p->right, w, num, found);
  return p;
}
/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
  if (p != NULL) {
    treexprint(p->left);
	if(p->match)
		printf("%s\n",p->word);
    treexprint(p->right);
  }
}

/* print in alphabetic order each group of variable names  */
/* identical in the first num chars (default 6) */
main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int found = NO; // YES if found
	int num;	//no of first ident chars
	
	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
	root = NULL;
	printf("num = %d\n",num);
	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtreex(root, word, num, &found);
		found = NO;
	}
	treexprint(root);
	return 0;
}

