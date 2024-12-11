#ifndef __ORDERED_TREE_H__
#define __ORDERED_TREE_H__

#include <assert.h>
#include <inttypes.h>

typedef struct node {
  void* data;
  struct node *left;
  struct node *right;
  int8_t balance;
} node;

typedef struct ordered_tree {
  node* root;
  uint64_t size;
  char type;
} ordered_tree;

void init_tree(ordered_tree** tree, char type);
void clear_tree_help(node* root, char type);
void clear_tree(ordered_tree* tree);

node* insert_help(node* root, char type, void* e);
void insert_tree(ordered_tree* tree, void* e);

void* find_help(node* root, char type, void* e);
void* find(ordered_tree* tree, void* e);

// show it in dfs order
void show_tree_help(node *root, char type);
void show_tree(ordered_tree *tree);

#endif
