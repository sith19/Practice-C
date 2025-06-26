#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Created by Yogev on 6/1/2025.
//
struct tnode;
struct BST;
struct tnode * search(struct BST * bst, char * word);
void insert(struct BST * bst, char * word);
void delete(struct BST * bst, char * word);
void display(struct BST * bst);
struct tnode
{
    char * word;
    struct tnode * left;
    struct tnode * right;
};
struct BST
{
    struct tnode * root;
    int size;

};
/*
void main()
{
    struct BST tree = {NULL, 0};
    insert(&tree, "banana");
    insert(&tree, "apple");
    insert(&tree, "cherry");
    display(&tree);
    printf("%s\n", tree.root-> word);
    delete(&tree, "banana");
    printf("After deleting 'banana':\n");
    display(&tree);
}*/



static struct tnode * search_helper(struct tnode * start, char * word)
{
    if (strcmp(start -> word,word) == 0)
    {
        return start;
    }
    else if (strcmp(word, start->word) < 0)
    {
        if (start -> left == NULL)
        {
            return NULL;
        }
        search_helper(start -> left, word);
    }else if (strcmp(word, start->word) > 0)
    {
        if (start -> right == NULL)
        {
            return NULL;
        }
        search_helper(start -> right, word);
    }

}

struct tnode * search(struct BST * bst, char * word)
{
    search_helper(bst -> root, word);
}
void insert_helper(struct tnode * start, char * word)
{
    if (search_helper(start, word)){
        printf("Word already exists\n");
        return;
    }
    if (start -> left == NULL  && (strcmp(word, start->word) < 0))
    {
        struct tnode * new_node = (struct tnode *)malloc(sizeof(struct tnode));
        new_node -> word = strdup(word);
        new_node -> left = new_node -> right = NULL;
        start -> left = new_node;
    }else if (start -> right == NULL && (strcmp(word, start->word) > 0))
    {
        struct tnode * new_node = (struct tnode *)malloc(sizeof(struct tnode));
        new_node -> word = strdup(word);
        new_node -> left = new_node -> right = NULL;
        start -> right = new_node;
    }
    else if (strcmp(word, start->word) < 0)
    {
        insert_helper(start->right, word);
    }else if (strcmp(word, start->word) > 0)
    {
        insert_helper(start->left, word);
    }
}
void insert(struct BST * bst, char * word)
{
    if (bst->root == NULL)
    {
        struct tnode * new_node = (struct tnode *)malloc(sizeof(struct tnode));
        new_node -> word = strdup(word);
        new_node -> left = new_node -> right = NULL;
        bst -> root =new_node;
        bst -> size ++;
    }else
    {
        insert_helper(bst -> root, word);
        bst -> size ++;
    }


}

struct tnode* getSuccessor(struct tnode* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}
static struct tnode *delete_helper(struct tnode *root, char *word) {
    if (root == NULL) return NULL;

    if (strcmp(word, root->word) < 0) {
        root->left = delete_helper(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = delete_helper(root->right, word);
    } else {
        if (root->left == NULL) {
            struct tnode *temp = root->right;
            free(root->word);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct tnode *temp = root->left;
            free(root->word);
            free(root);
            return temp;
        }
        // Two children
        struct tnode *temp = getSuccessor(root);
        free(root->word);  // Free current word
        root->word = strdup(temp->word); // Deep copy
        root->right = delete_helper(root->right, temp->word); // Delete successor
    }
    return root;
}
void delete(struct BST * bst, char * word){
    bst -> root = delete_helper(bst->root, word);
    bst -> size --;
}
static void display_helper(struct tnode *node) {
    if (node == NULL) return;
    display_helper(node->left);
    printf("%s ", node->word);
    display_helper(node->right);
}
void display(struct BST *bst) {
    printf("BST contents (in-order):\n");
    display_helper(bst->root);
    printf("\n");
}

