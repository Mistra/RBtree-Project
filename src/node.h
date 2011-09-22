#ifndef NODE_H
#define NODE_H

#define RED false
#define BLACK true

class node {
 public:

  node(float);

  node* father() const;
  node* sibling() const;
  node* granny() const;
  node* uncle() const;
  node* right() const;
  node* left() const;
  bool is_right() const;
  bool is_left() const;
  float value() const;
  bool color() const;

  void set_father(node* const);
  void set_left(node* const);
  void set_right(node* const);
  void set_color(bool);
  void swap_color();

 private:
  bool _color;
  float _value;
  node* _father;
  node* _left_son;
  node* _right_son;
};

#endif //NODE_H
