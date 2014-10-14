#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define YES 1
#define NO 0
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;
  if(p == NULL) {  /* a new word has arrived */
    p = talloc();  /* make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;   /* repeated word */
  else if(cond< 0)/* less than into left subtree */
    p->left = addtree(p->left, w);
  return p;
}

    

void treeprint(struct tnode *)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}
int getword(char *,int);

/* word frequency count */
main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
