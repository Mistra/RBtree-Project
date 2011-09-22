#include "node.h"
#include <cstdlib>
#include <cassert>

node::node(float val): _value(val) {
  _color=RED;
}

node*
node::father() const {
  return _father;
}

node*
node::sibling() const {
  if ( _father->_left_son == this)
    return _father->_right_son;
  else
    return _father->_left_son;
}

node*
node::granny() const {
  return _father->_father;
}

node*
node::uncle() const {
  if ( granny()->right() == _father )
    return granny()->left();
  return granny()->right();
}

node*
node::right() const {
  return _right_son;
}

node*
node::left() const {
  return _left_son;
}

bool
node::is_right() const {
  if (_father==NULL)
    return false;
  if (_father->_right_son == this)
    return true;
  return false;
}

bool
node::is_left() const {
  if (_father==NULL)
    return false;
  if (_father->_left_son == this)
    return true;
  return false;
}

float
node::value() const {
  return _value;
}

bool
node::color() const {
  return _color;
}

void
node::set_father(node* const newone) {
  assert (newone!=NULL);
  _father=newone;
}

void
node::set_left(node* const newone) {
  assert (newone!=NULL);
  _left_son=newone;
}

void
node::set_right(node* const newone) {
  assert (newone!=NULL);
  _right_son=newone;
}

void
node::set_color(bool new_color) {
  _color=new_color;
}

void
node::swap_color() {
  _color=!_color;
}
