#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct tree_node
{
    char name;
    char pass;
    unsigned int depth;
    unsigned int is_banch;
    struct tree_node* left_child;
    struct tree_node* right_child;
} node;

node* InsertUser(char name, char pass, node* poss, int d);

void ShowTree(node* tree);