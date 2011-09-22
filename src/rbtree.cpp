#include <cassert>
#include "rbtree.h"

const bool RIGHT=true;
const bool LEFT=false;

rbtree::rbtree(): tree() {
  sentry->set_color(BLACK);
}

node*
rbtree::insert (const float num) {
  node* newnode=tree::insert (num);
  first_case(newnode);
  return newnode;
}

/*
node*
rbtree::remove (const float num) {
  node* target=search(num);
  node* x;
  target=tree::remove_fix(target, x);
  if (target->color()==BLACK) {
    if (x->color()==RED)
      x->swap_color();
    else
      remove_first_case(x);
  }
  delete target;
  return sentry;
}
*/
rbtree::~rbtree(){
}

void
rbtree::first_case (node* newnode) {
  if ( newnode->father() == sentry ){
    headnode = newnode;
    newnode->swap_color();
  }
  else second_case(newnode);
}

void
rbtree::second_case (node* newnode) {
  if ( newnode->father()->color() == BLACK ){
    return;
  }
  else
    third_case(newnode);
}

void
rbtree::third_case (node* newnode) {
  if ( (newnode->uncle() != sentry) and
       (newnode->uncle()->color() == RED) ) {
    newnode->uncle()->swap_color();
    newnode->father()->swap_color();
    newnode->granny()->swap_color();
    first_case( newnode->granny() );
  }
  else
    fourth_case(newnode);
}

void
rbtree::fourth_case (node* newnode) {
  if (newnode == newnode->father()->right() and //figli dx di p.
      newnode->father() == newnode->granny()->left() ){
    rotate_left(newnode->father() );
    fifth_case (newnode->left() );
    return;
  }
  else if (newnode == newnode->father()->left() and
	   newnode->father() == newnode->granny()->right() ){
    rotate_right(newnode->father() );
    fifth_case (newnode->right() );
    return;
  }
  fifth_case (newnode);
}

void
rbtree::fifth_case (node* newnode) {
  newnode->father()->swap_color();
  newnode->granny()->swap_color();
  if ( newnode == newnode->father()->left() and
       newnode->father() == newnode->granny()->left() ) {
    rotate_right(newnode->granny() );
  }
  else {
    rotate_left(newnode->granny() );
  }
}

/*
// If x is headnode we are ok
void
rbtree::remove_first_case(node* n) { // test
  if ( n->father() == sentry ){
    return;
  }
  else
    remove_second_case(n);
}

// Brother is red, so father is black.
// I don't check for null because there MUST
// be a sibling not leaf.
void
rbtree::remove_second_case(node* n) {
  if ( n->sibling()->color() == RED ) {
    n->father()->swap_color();
    n->sibling()->swap_color();
    if ( n->is_left() )
      rotate_left ( n->father() );
    else
      rotate_right ( n->father() );
  }
  remove_third_case(n);
}

void
rbtree::remove_third_case(node* n) {
  if (n->father()->color() == BLACK and
      n->sibling()->color() == BLACK and
      n->sibling()->left()->color() == BLACK and
      n->sibling()->right()->color() == BLACK) {
    n->sibling()->swap_color();
    remove_first_case( n->father() );
  }
  else
    remove_fourth_case(n);
}

void
rbtree::remove_fourth_case(node* n) {
  if (n->father()->color() == RED and //<-- almost 200% cure this isn't needed!
      n->sibling()->color() == BLACK and
      n->sibling()->left()->color() == BLACK and
      n->sibling()->right()->color() == BLACK) {
    n->sibling()->swap_color();
    n->father()->swap_color();
  }
  else
    remove_fifth_case(n);
}

void
rbtree::remove_fifth_case(node* n) {
  if (n->is_left() &&
      n->sibling()->color() == BLACK &&
      n->sibling()->left()->color() == RED &&
      n->sibling()->right()->color() == BLACK) {
    n->sibling()->swap_color();
    n->sibling()->left()->swap_color();
    rotate_right ( n->sibling() );
  }
  else if (n->is_right() &&
	   n->sibling()->color() == BLACK &&
	   n->sibling()->right()->color() == RED &&
	   n->sibling()->left()->color() == BLACK) {
    n->sibling()->swap_color();
    n->sibling()->right()->swap_color();
    rotate_left ( n->sibling() );
  }
  remove_sixth_case(n);
}

void
rbtree::remove_sixth_case(node* n) {
  n->sibling()->set_color (n->father()->color() ) ;
  n->father()->swap_color();
  if ( n->is_left() ) {
    // Here, sibling(n)->right->color == RED
    n->sibling()->right()->swap_color();
    rotate_left ( n->father() );
  }
  else {
    // Here, sibling(n)->left->color == RED
    n->sibling()->left()->swap_color();
    rotate_right ( n->father() );
  }
}
*/

void
rbtree::rotate_right (node* f) {
  node* s=f->left();
  node* b=s->right();
  node* g=f->father();
  link(g, s, f->is_right() );
  link(s, f, RIGHT);
  link(f, b, LEFT);
  if ( s->father()==sentry )
    headnode=s;
}
//rotations still not valit with equal numbers e.g. 5 and 5
void
rbtree::rotate_left (node* f) {
  node* s=f->right();
  node* b=s->left();
  node* g=f->father();
  link(g, s, f->is_right() );
  link(s, f, LEFT);
  link(f, b, RIGHT);
  if ( s->father()==sentry )
    headnode=s;
}

