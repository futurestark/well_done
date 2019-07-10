#include <iostream>

class X {
 public:
  void addXProperty() {
    std::cout << "Add X property" << std::endl;
  }
};

class Y {
 public:
  void addYProperty() {
    std::cout << "Add Y property" << std::endl;
  }
};

class XYZ: private X, private Y {
 public:
  void addXYZProperty() {
    addXProperty();
    addYProperty();
    std::cout << "Add Z property" << std::endl;
  }
};


class A {
 public:
  void print() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;   
  }
};

class B {
 public:
  void print() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

class C : public A, public B {};

/*Diamond problem*/

class Base {
public:
 /*...*/
protected:
  int data_;
};
class Der1 : public virtual Base { /*...*/ };
class Der2 : public virtual Base { /*...*/ };
class Join : public Der1, public Der2 {
public:
  void method()
  {
     data_ = 1;
  }
};
/*********InMemory*****************/
/*     *************              */
/*     *  Base     *              */
/*     *  Der1     *              */
/*     *************              */
/*                                */
/*     *************              */
/*     *  Base     *              */
/*     *  Der2     *              */
/*     *************              */
/*                                */
/*          Join                  */
/**********************************/

/*
    *******     ******
    *Base *     *Base*
    *******     ******
       *          *
    *******     ******
    *Der1 *     *Der2*
    *******     ******
       *         *
        *       *
          *******
          *Join *
          *******
*/

/*
          ******
          *Base*
          ******
          *   *
         *     *     
    *******     ******
    *Der1 *     *Der2*
    *******     ******
       *         *
        *       *
          *******
          *Join *
          *******
*/

/*

    ********
    * Der1 * ********
    ********        *
                    *
    ********        *
    * Der1 * *****  *
    ********     *  *
                 *  *
      Join       *  *
                 *  *
    ********     *  *
    * Base *  *******
    ********
*/
int main(int argc, char const *argv[]) {
    XYZ xyz;
    xyz.addXYZProperty();

    C c;
    // c.print();
    c.A::print();



    Join* join = new Join();
    Base* base = join;
    return 0;
}
