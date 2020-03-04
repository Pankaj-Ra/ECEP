#include <iostream>

class Other {
    public:
          ~Other() {
                  std::cout << "Other Destroyed" << std::endl;
                    }
};

class Base {
    public:
          ~Base(){}
};

class Derived : public Base {
    private:
          Other o;
    public:
            ~Derived(){}
};

int main() {
      Base *b = new Derived();
        delete b;
}
