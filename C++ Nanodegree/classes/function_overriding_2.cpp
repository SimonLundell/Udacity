#include <assert.h>
#include <cmath>
#define PI 3.14159

class VehicleModel {
    // Has to be set "= 0" to tell complier that the base-class will not define the function, it is a pure abstract function
    virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public VehicleModel {
    public:
      void Move(double v, double phi) override;
    
      double x = 0;
      double y = 0;
      double theta = 0;
};

void ParticleModel::Move(double v, double phi) {
    theta += phi;
    x += v * cos(theta);
    y += v * cos(theta);
}

class BicycleModel : public ParticleModel {
    public:
      void Move(double v, double phi) override;
      
      //Inherits x,y and theta from ParticleModel, no need to define again.
      double L = 1;
};

void BicycleModel::Move(double v, double phi) {
    theta += v / L * tan(phi);
    x += v * cos(theta);
    y += v * cos(theta);
}

int main() {
  ParticleModel particle;
  BicycleModel bicycle;
  
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}