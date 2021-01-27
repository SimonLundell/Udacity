#include <iostream>
#include <string>
using std::string;
using std::cout;

// The Car class
class Car {
  public:
    /* IF I CREATE THE CONSTRUCTOR, I HAVE TO CALL THE CLASS WITH A CONSTRUCTOR AS WELL.
    Car(string c, int n) {
        color = c;
        number = n;
    
    }*/
    // Method to print data.
    void PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }
    
    // Method to increment the distance travelled.
    void IncrementDistance() 
    {
        distance++;
    }
    
    // Class/object attributes
    string color;
    int distance = 0;
    int number;
};

int main() 
{
    // Create class instances for each car.
    Car car_1, car_2, car_3;

    //Car car_1 = Car("green",1); Uncomment this line if there is a constructor in the class.

    // Set each instance's color.
    car_1.color = "green";
    car_2.color = "red";
    car_3.color = "blue";

    // Set each instance's number.
    car_1.number = 1;
    car_2.number = 2;
    car_3.number = 3;

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();

}