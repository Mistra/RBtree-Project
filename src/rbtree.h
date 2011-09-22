#ifndef RBTREE_H
#define RBTREE_H

#include "tree.h"

class rbtree : public tree {
 public:
  rbtree();
  node* insert (const float);
  // node* remove (const float);
  ~rbtree();

 private:

  void first_case (node*);
  void second_case (node*);
  void third_case (node*);
  void fourth_case (node*);
  void fifth_case (node*);
  /*  void remove_first_case(node*);
  void remove_second_case(node*);
  void remove_third_case(node*);
  void remove_fourth_case(node*);
  void remove_fifth_case(node*);
  void remove_sixth_case(node*);
  */
  void rotate_right (node*);
  void rotate_left (node*);

};

#endif //RBTREE_H
