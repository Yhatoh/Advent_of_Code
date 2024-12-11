#ifndef __ORDERED_TREE__
#define __ORDERED_TREE__

// c includes
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// local includes
#include "ordered_tree.h"
#include "util.h"

// Ordered Tree: is an ordered tree based on avl

void init_tree(ordered_tree** tree, char type) {
  assert(type == 'I' || type == 'c' || type == 'p');

  *tree = (ordered_tree*) malloc(sizeof(ordered_tree));
  (*tree)->root = NULL;
  (*tree)->type = type;
  (*tree)->size = 0;
}

void clear_tree_help(node* root, char type) {
  if(root == NULL) return;

  clear_tree_help(root->left, type);
  clear_tree_help(root->right, type);

  if(type == 'p') clear_pair(root->data);
  else free(root->data);
  free(root);
}

void clear_tree(ordered_tree* tree) {
  clear_tree_help(tree->root, tree->type);
  free(tree);
}

node* insert_help(node* root, char type, void* e) {
  if(root == NULL) {
    node* ret = (node*) malloc(sizeof(node));
    ret->data = e;
    if(type == 'I') {
      ret->data = malloc(sizeof(int64_t));
      int64_t* aux = ret->data;
      *aux = *((int64_t*) e);
    } else if(type == 'c') {
      ret->data = malloc(sizeof(char));
      char* aux = ret->data;
      *aux = *((char*) e);
    } else if(type == 'p') {
      ret->data = e;
    }
    ret->left = ret->right = NULL;
    ret->balance = 0;
    return ret;
  }

  int8_t ret_comp = comp(root->data, e, type);

  if(ret_comp < 0) {
    root->right = insert_help(root->right, type, e);
  } else if(ret_comp > 0) {
    root->left = insert_help(root->left, type, e);
  }

  return root;
}

void insert_tree(ordered_tree* tree, void* e) {
  tree->root = insert_help(tree->root, tree->type, e);
}

void* find_help(node* root, char type, void* e) {
  if(root == NULL) return NULL;


  int8_t ret_comp = comp(root->data, e, type);

  if(ret_comp < 0) {
    return find_help(root->right, type, e);
  } else if(ret_comp > 0) {
    return find_help(root->left, type, e);
  }

  return root;
}

void* find(ordered_tree* tree, void* e) {
  return find_help(tree->root, tree->type, e);
}
  
void show_tree_help(node* root, char type) {
  if(root == NULL) return;

  show_tree_help(root->left, type);
  
  if(type == 'I') {
    printf("%" PRId64 " ", *((int64_t*) root->data));
  } else if(type == 'c') {
    printf("%c ", *(((char*) root->data)));
  } else if(type == 'p'){
    show_pair((pair*) root->data); printf(" ");
  }

  show_tree_help(root->right, type);
}

void show_tree(ordered_tree* tree) {
  printf("{ ");
  show_tree_help(tree->root, tree->type);
  printf("}");
}

#endif /* ifndef __ORDERED_TREE__ */
