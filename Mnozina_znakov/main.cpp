#include <iostream>
#include <string.h>

using namespace std;

struct Node_t{
    char character;
    Node_t *left, *right;
};
typedef struct{
    Node_t *data;
}Set_t;

Node_t *createNode(char c){
    Node_t *u = new Node_t;
    u->character = c;
    u->left = NULL;
    u->right = NULL;
    return u;
}

Node_t *push(Node_t *root, char c){
    if (root == NULL){
        return createNode(c);
    }

    if(c < root->character){
        root->left = push(root->left, c);
    } else {
        root->right = push(root->right, c);
    }
    return root;
}

Node_t *search_node(Node_t *root, char c){
    if(root == NULL){
        return NULL;
    }
    if(c == root->character){
        return root;
    }

    if(c < root->character){
        return search_node(root->left, c);
    } else {
        return search_node(root->right, c);
    }

}

int set_contains(Set_t *s, char c){
    if(search_node(s->data, c) == NULL){
        return 0;
    }
    return 1;
}


void set_push(Set_t *s, char c){

    if(!set_contains(s,c)){
    s->data = push(s->data, c);
    }
}

void print(Node_t *root){
    if (root != NULL){
    print(root->left);
    cout<<root->character;
    print(root->left);
    }
}

void set_print(Set_t *s){
    print(s->data);
}
int main()
{
    char row[101];
    cin>>row;
    /*
    Node_t *tree = NULL;
    for (int i=0; i<strlen(row); i++){
        tree = push(tree, row[i]);
    }
    print(tree);
    print(search_node(tree, 'c'));
    */
    Set_t *mySet = new Set_t;
    mySet->data = NULL;
    for (int i=0; i<strlen(row); i++){
        set_push(mySet, row[i]);
    }
    set_print(mySet);
    return 0;
}
