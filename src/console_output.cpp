#include <iostream>
#include "node.h"
#include "tree.h"
#include "console_output.h"

using namespace std;

void
console_output::t_paint(const tree& t) {
  r_paint(t.get_headnode(), t);
}

char
console_output::colore(bool c){
  if(c) return 'b';
  else return 'r';
}

void
console_output::r_paint(node* n, const tree& t){
  if (n==t.get_sentry()) return;
  r_paint(n->left(), t);
  n_paint(n, t);
  r_paint(n->right(), t );
}

void
console_output::n_paint(node* n, const tree& t){
  cout<<"N:"
      <<n->value()<<'\t'<<"|";

  cout<<"L:";
  if ( n->left()==t.get_sentry() )
    cout<<"LEAF"<<'\t'<<"|";
  else
    cout<<n->left()->value()<<'\t'<<"|";

  cout<<"R:";
  if ( n->right()==t.get_sentry() )
    cout<<"LEAF"<<'\t'<<"|";
  else
    cout<<n->right()->value()<<'\t'<<"|";

  cout<<"F:";
  if ( n->father()==t.get_sentry() )
    cout<<"NULL"<<'\t'<<"|";
  else
    cout<<n->father()->value()<<'\t'<<"|";

  cout <<"C:"
       <<colore(n->color() )<<endl;
}

/*void
console_output::interactive_paint(node* n, const tree& t){
  int h=t.hight();
  }*/
