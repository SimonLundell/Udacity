#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
  public:
    Pyramid(int l, int w, int h);
    int Length() { return length_; }
    int Width() { return width_; }
    int Height() { return height_; }
    
    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);
    
    float Volume();
    bool Valid(int dim);
    
  private:
    int length_{0};
    int width_{0};
    int height_{0};
};

Pyramid::Pyramid(int l, int w, int h) {
    setLength(l);
    setWidth(w);
    setHeight(h);
}

void Pyramid::setLength(int length) {
    Valid(length);
    length_ = length;
}

void Pyramid::setWidth(int width) {
    Valid(width);
    width_ = width;
}

void Pyramid::setHeight(int height) {
    Valid(height);
    height_ = height;
}

float Pyramid::Volume() {
    return (Length() * Width() * Height()) / 3.0;
}

bool Pyramid::Valid(int dim) {
    if (dim < 0)
        throw "Not ok";
}

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}