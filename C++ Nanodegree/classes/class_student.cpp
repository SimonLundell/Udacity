#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Student {
 public:
  // constructor. List initializer instantly setting the private members and then calling Valid() to see if they are withing bounds
    Student(string name, int grade, float GPA) : name(name), grade(grade), GPA(GPA) { Valid(); }

  // accessors
    string getName() const { return name; }
    int getGrade() const { return grade; }
    float getGPA() const { return GPA; }
    
  // mutators.
    void setName(string n){ 
        name = n;
        Valid();
    }
    void setGrade(int g){ 
        grade = g; 
        Valid();
    }
    void setGPA(float gpa){ 
        GPA = gpa; 
        Valid();
    }

 private:
    string name{"John"};
    int grade{0};
    float GPA{0};
    // Private function that checks if grade and GPA are within bounds
    void Valid() {if (getGrade() < 0 || getGrade() > 12 || getGPA() < 0 || getGPA() > 4) throw invalid_argument("Negative val");}
};

int main() {
    Student simon("Simon", 6, 4.5);
    assert(simon.getName() == "Simon");
    assert(simon.getGrade() == 6);
    assert(simon.getGPA() == 4.5);
    
    /* Uncomment to run!
    bool caught{false};
    try {
        Student valid("Ken",1, -3);
    } catch (...) {
        caught = true;
    }
    */

    bool caught{false};
    try {
        simon.setGPA(-3);
    } catch (...) {
        caught = true;
    }

    assert(caught);
}