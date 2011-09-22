#include <cassert>
#include <cstdlib>
#include "tree.h"

const bool RIGHT=true;
const bool LEFT=false;

tree::tree(): node_number(0) {
  sentry=new node(0);
  headnode=sentry;
}

tree::~tree(){
  delete sentry;
}

node*
tree::insert (const float num) {
  node* newnode = new node(num);
  node* father = find_father(headnode, newnode);
  if ( father == sentry )
    headnode=newnode;
  if ( (newnode->value() ) > ( father->value() ) )
    link (father, newnode, RIGHT);
  else
    link (father, newnode, LEFT);
  newnode->set_right (sentry);
  newnode->set_left (sentry);
  return newnode;
}

node*
tree::find_father (node* father, node* newnode) {
  assert (father!=NULL);
  if ( father == sentry )
    return father;
  while (true){
    if ( newnode->value() > father->value() and
	 father->right() != sentry )
      father=father->right();
    else if ( newnode->value() <= father->value() and
	 father->left() != sentry )
      father=father->left();
    else
      return father;
  }
}

void
tree::link (node* father, node* son, bool side) { //RIGHT=true LEFT=false
  assert (father!=NULL);
  assert (son!=NULL);
  if (side) // RIGHT
    father->set_right(son);
  else // LEFT
    father->set_left(son);
  son->set_father(father);
}

node*
tree::successor (node* n) const {
  node* successor=n->right();
  assert (successor!=sentry);
  while(true) {
    if ( successor->left() == sentry )
      return successor;
    successor=successor->left();
  }
}

node*
tree::search (const float num) const {
  node* actual=headnode;
  while (true) {
    if ( actual == sentry or actual->value() == num)
      return actual;
    else if ( actual->value() < num )
      actual=actual->right();
    else
      actual=actual->left();
  }
}

void
tree::remove (const float num) {
  node* target=search(num);
  if (target==sentry)
    throw "Can't remove unexisting node";
  node* aux=target;
  if (target->left() != sentry and
      target->right() != sentry)
    aux=successor(target);
  remove_fix_one(aux);
  if (aux!=target)
    remove_fix_two(target, aux);
  delete target;
}

void
tree::remove_fix_one(node* target) {
  assert(target!=sentry);
  node* son;
  if (target->right() == sentry)
    son=target->left();
  else
    son=target->right();
  link (target->father(), son, target->is_right() );
  if (target == headnode)
    headnode=son;
}

void
tree::remove_fix_two(node* target, node* aux) {
  link (target->father(), aux, target->is_right() );
  link (aux, target->right(), RIGHT);
  link (aux, target->left(), LEFT);
  if (target == headnode)
    headnode=aux;
}
