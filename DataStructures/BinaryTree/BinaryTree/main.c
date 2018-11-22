# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

////////////////////            (Binary Trees)



struct tree_node{

    int value;
    struct tree_node * left;
    struct tree_node * right;

};

typedef struct tree_node tree_node;

struct tree{

    int size;   //number of nodes
    tree_node * root;

};

typedef struct tree tree;

tree * create_tree(){

    tree * t = (tree *) malloc(sizeof(tree));
    t->size = 0;
    t->root = NULL;
    return t;

}

bool empty_tree(tree * t){

    return t->size==0;

}


void insert_node(tree * t, int value){

    tree_node * tn = (tree_node *) malloc(sizeof(tree_node));
    tn->value = value;
    tn->left = tn->right = NULL;

    if(empty_tree(t)){
        t->root = tn;
        t->size++;
        return ;
    }

    tree_node * root = t->root;

    while(true)
    {
        if(value < root->value)
        {
            if(root->left == NULL)
            {
                root->left = tn;
                t->size++;
                return ;
            }
            else
                root = root->left;
        }
        else if(value > root->value)
        {
            if(root->right == NULL)
            {
                root->right = tn;
                t->size++;
                return ;
            }
            else
                root = root->right;
        }
        else
            break;
    }

}

void print_tree(tree_node * root)
{
    if(root == NULL) return;
    print_tree(root->left);
    printf("%d\t", root->value);
    print_tree(root->right);

}

int main(int argc, char **argv){

    tree * t = create_tree();
    insert_node(t,5);
    insert_node(t,7);
    insert_node(t,3);
    insert_node(t,4);
    insert_node(t,8);
    print_tree(t->root);
    return 0;
}

