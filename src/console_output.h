#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

class console_output {

 public:
  void t_paint(const tree&);
  void r_paint(node*, const tree&);
  void n_paint(node*, const tree&);

  //void interactive_paint(node*, const tree&);

 private:
  char colore(bool);
};

#endif //console_output
