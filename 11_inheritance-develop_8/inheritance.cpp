#include <iostream>

class People {
 public:
  void print() {
    std::cout << id << " " << age << std::endl;
  }
  People(unsigned id, unsigned age)
   : id(id), age(age) {
    
  }
  People()
   : id(0), age(0) {
    
  }
 private:
  unsigned id;
  unsigned age;
};

class Student: public People {
 public:
  Student(unsigned id, unsigned age, unsigned group)
   : /*People(id, age),*/ group(group) {

  }
  void print() {
    People::print();
    std::cout << group << std::endl;
  }
 private:
  unsigned group;
};

class Base {
  public:
   void print() {
     std::cout << "I'm from base class" << std::endl;
   }
};

class Derived: public Base {
  public:
   void hello() {
     std::cout << "I'm from derived class" << std::endl;
   }
};

class DerivedPrivate: private Base {
  public:
   void hello() {
     std::cout << "I'm from derived class" << std::endl;
   }
   void wrapper_print() {
     std::cout << "I'm call method print base class via wrapper" << std::endl;
     print();
   }
};

class A {
  int a;  
};

class B: public A {
  int c;  
};

class BaseShadow {
 public:
  void calc(int i) {
    std::cout << __PRETTY_FUNCTION__ << std::endl; 
  }
  void calc(double i) {
    std::cout << __PRETTY_FUNCTION__ << std::endl; 
  } 

  void calc(double d, int i) {
    std::cout << __PRETTY_FUNCTION__ << std::endl; 
  }
};

class DerivedShadow: public BaseShadow {
 public:
  using BaseShadow::calc;

  void calc() {
    std::cout << __PRETTY_FUNCTION__ << std::endl; 
  }
};

class One {
 public:
  One() {
    std::cout << "ctr One" << std::endl; 
  }

  ~One() {
    std::cout << "dtr One" << std::endl; 
  }
};

class Two {
 public:
  Two() {
    std::cout << "ctr Two" << std::endl; 
  }

  ~Two() {
    std::cout << "dtr Two" << std::endl; 
  }
};

class Three: public One {
 public:
  Three() {
    std::cout << "ctr Three" << std::endl; 
  }

  ~Three() {
    std::cout << "dtr Three" << std::endl; 
  }
 private:
  Two tw;
};

int main(int argc, char const *argv[]) {
    std::cout << sizeof(B) << " " << sizeof(A) << std::endl;
    Student student(100, 21, 10);
    student.print();
    student.People::print();
    Derived d;
    d.hello();
    d.print();
    Base b;
    b.print();

    Base& base = d;
    base.print();
    // error: ‘class Base’ has no member named ‘hello’
    // base.hello();

    DerivedPrivate dp;
    dp.hello();
    // dp.print();
    dp.wrapper_print();

    /*Base base_private = dp;*/
    DerivedShadow d_shadow;
    d_shadow.calc();
    d_shadow.calc(10);

    std::cout << "Destructor" << std::endl;

    Three three;
    return 0;
}
