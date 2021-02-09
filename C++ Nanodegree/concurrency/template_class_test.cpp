#include <iostream>
#include <string>

using namespace std;

template <class X>
class Test {
    public:
      Test(X inp) { var1 = inp; }
      void print() { std::cout << "Hello! " << var1 << endl; }
    
    private:
      X var1;
};

int main() {
    Test<int> a(10);
    Test<string> b("Fuck");
    a.print();
    b.print();

    Test<double> * c = new Test<double>(50.0);
    c->print();
}