#include <iostream>
#include <vector>

class Dot {
    public:
        Dot(int x = 0, int y = 0) : x_(x), y_(y) {}; // setting x,y = 0 acts as default constructor, dont have to specify values on creation.
        int x_;
        int y_;
        
        // Operator overloading of class has to be specified within the class;
        Dot operator-(const Dot &d) { 
            Dot p;
            p.x_ = x_ - d.x_;
            p.y_ = y_ - d.y_;

            return p;
        }
};

// Outside of a class, 2 inputs to the overloading can be specified and referenced as below.
std::vector<int> operator+(const std::vector<int> &v1, const std::vector<int> &v2) {
    std::vector<int> sum{};
    for (int i = 0; i < v1.size(); i++) {
        sum.push_back(v1[i] + v2[i]);
    }
    return sum;
}

int main() {
    std::vector<int> a{1,2,3,4};
    std::vector<int> b{5,6,7,8};
    std::vector<int> c = a + b;

    for (int &i : c) std::cout << i << " ";
    std::cout << "\n";

    std::vector<int> d{1,1,1,1,1,1,1};
    std::vector<int> e{2,2,2,2,2,2,2};
    std::vector<int> f = d + e;
    for (int &i : f) std::cout << i << " ";
    std::cout << "\n";

    Dot dot1(5,10);
    Dot dot2(2,4);

    Dot dot3 = dot1 - dot2;
    std::cout << dot3.x_ << " " << dot3.y_ << "\n";
}