//The functions below can be written in any order, but having them as below is encouraged to avoid complex programs failing

#include <iostream>

float distance(float velocity, float time_elapsed);

int main()
{
	std::cout <<distance(5, 4) << std::endl;
	std::cout <<distance(12.1, 7.9) << std::endl;
}


float distance(float velocity, float time_elapsed)
{
	return velocity * time_elapsed;
}
