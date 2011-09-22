#ifndef TREE_H
#define TREE_H

#include "node.h"

class tree {
 public:
  tree();
  virtual ~tree();
  virtual node* insert(const float);
  virtual void remove(const float);
  node* get_headnode() const;
  node* get_sentry() const;
  node* search(const float) const;

 protected:
  void link(node*, node*, bool);
  void remove_fix_one(node*);
  void remove_fix_two(node*, node*);
  node* successor(node*) const;

 protected:
  int node_number; //not usable yet
  node* headnode;
  node* sentry;

 private:
  node* find_father(node*, node*);
};

#include "tree.inlines.h"

#endif //TREE_H
