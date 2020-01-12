# All [x*x for x,y in zip()] type functions below are "Generator expressions", which will ease the calculation when using tuples containing coordinates

from math import sqrt
from math import *
from decimal import Decimal, getcontext

getcontext().prec = 30

class Vector(object):
    # Creates vector based on an input list of coordinates and also sets the dimensions of the space
    # that the vector lives in.
    
    CANNOT_NORMALIZE_ZERO_VECTOR_MSG = 'Cannot normalize the zero vector'

    def __init__(self, coordinates):
        try:
            if not coordinates:
                raise ValueError
            self.coordinates = tuple([Decimal(x) for x in coordinates])
            self.dimension = len(self.coordinates)

        except ValueError:
            raise ValueError('The coordinates must be nonempty')

        except TypeError:
            raise TypeError('The coordinates must be an iterable')

    def plus(self, v):
        new_coordinates = [x+y for x,y in zip(self.coordinates, v.coordinates)]
        return new_coordinates

    def minus(self, v):
        new_coordinates = [x-y for x,y in zip(self.coordinates, v.coordinates)]
        return Vector(new_coordinates)

    def times_scalar(self, c):
        new_coordinates = [Decimal(c)*x for x in self.coordinates]
        return Vector(new_coordinates)
    
    def magnitude(self):
        coordinates_squared = [x*x for x in self.coordinates]
        return sqrt(sum(coordinates_squared))

    def normalized(self):
        try:
            magnitude = self.magnitude()
            return self.times_scalar(Decimal(1.0)/Decimal(magnitude))
 
        except ZeroDivisionError:
            raise Exception(self.CANNOT_NORMALIZE_ZERO_VECTOR_MSG)
                        
    def dot_product(self, v):
        new_coordinates = [x*y for x,y in zip(self.coordinates, v.coordinates)]
        return sum(new_coordinates)

    def angle(self, v, in_degrees=False):
        try:
            u1 = self.normalized()
            u2 = v.normalized()
            angle_in_radians = acos(round(u1.dot_product(u2), 5))

            if in_degrees:
                degrees_per_radian = 180. / pi
                return angle_in_radians * degrees_per_radian
            else:
                return angle_in_radians
               
        except Exception as e:
            if str(e) == self.CANNOT_NORMALIZE_ZERO_VECTOR_MSG:
                raise Exception('Cannot compute an angle with the zero vector')
            else:
                raise e

    def is_orthogonal_to(self, v, tolerance=1e-10):
        return abs(self.dot_product(v)) < tolerance

    def is_parallel_to(self, v):
        return ( self.is_zero() or 
                v.is_zero() or 
                self.angle(v) == 0 or 
                self.angle(v) == pi )

    def is_zero(self, tolerance=1e-10):
        return self.magnitude() < tolerance

    def orthogonal_to(self, v):
        try:
            proj = self.projection_of(v)
            return self.minus(proj)
        except Exception as e:
            if str(e) == self.NO_UNIQUE_PARALLEL_COMPONENT_MSG:
                raise Exception(self.NO_UNIQUE_PARALLEL_COMPONENT_MSG)
            else:
                raise e

    def projection_of(self, v): 
        try:
            u1 = v.normalized()
            u2 = self.dot_product(u1)
            return u1.times_scalar(u2)
        except Exception as e:
            if str(e) == self.CANNOT_NORMALIZE_ZERO_VECTOR_MSG:
                raise Exception(self.NO_UNIQUE_PARALLEL_COMPONENT_MSG)
            else:
                raise e

    def cross_product(self, v):
        try: 
            x1, y1, z1 = self.coordinates
            x2, y2, z2 = v.coordinates
            cross = [(y1*z2-y2*z1), -(x1*z2-x2*z1), (x1*y2-x2*y1)]
            return Vector(cross)
        except ValueError as e:
            msg = str(e)
            if msg == 'need more than 2 values to unpack':
                self_embedded_in_R3 = Vector(self.coordinates + ('0',))
                v_embedded_in_R3 = Vector(v.coordinates + ('0',))
                return self_embedded_in_R3.cross_product(v_embedded_in_R3)
            elif (msg == 'too many values to unpack' or 
                    msg == 'need more than 1 value to unpack'):
                raise Exception(self.ONLY_DEFINED_IN_TWO_THREE_DIM_MSG)
            else:
                raise e

    def prlgrm_area(self, v):
        u1 = self.cross_product(v)
        p_a = u1.magnitude()
        return p_a

    def tri_area(self, v):
        return 0.5*(self.prlgrm_area(v))

    def __str__(self):
        return 'Vector: {}' .format(self.coordinates)

    def __eq__(self, v):
        return self.coordinates == v.coordinates

"""
print 'Cross Product'
v = Vector([8.462, 7.893, -8.187])
w = Vector([6.984, -5.975, 4.778])
print v.cross_product(w)

print '\nParallelogram area'
v = Vector([-8.987, -9.838, 5.031])
w = Vector([-4.268, -1.861, -8.866])
print v.prlgrm_area(w)

print '\nTriangle area'
v = Vector([1.5, 9.547, 3.691])
w = Vector([-6.007, 0.124, 5.772])
print v.tri_area(w)


print '#1'
v = Vector([3.039, 1.879])
w = Vector([0.825, 2.036])
print v.projection_of(w)

print '\n#2'
v = Vector([-9.88, -3.264, -8.159])
w = Vector([-2.155, -9.353, -9.473])
print v.orthogonal_to(w)

print '\n#3'
v = Vector([3.009, -6.172, 3.692, -2.51])
w = Vector([6.404, -9.144, 2.759, 8.718])
vpar = v.projection_of(w)
vort = v.orthogonal_to(w)
print 'Parallel: ', vpar
print 'Orthogonal: ', vort

print('1st')
v = Vector([5, 5])
w = Vector([0, 0])
print v
print w
print('Is orthogonal: ', v.is_orthogonal_to(w), 'Is parallel: ', v.is_parallel_to(w))

print('2nd')
v = Vector([-2.029, 9.97, 4.172])
w = Vector([-9.231, -6.639, -7.245])
print('Is orthogonal: ', v.is_orthogonal_to(w), 'Is parallel: ', v.is_parallel_to(w))

print('3rd')
v = Vector([-2.328, -7.284, -1.214])
w = Vector([-1.821, 1.072, -2.94])
print('Is orthogonal: ', v.is_orthogonal_to(w), 'Is parallel: ', v.is_parallel_to(w))

print('4th')
v = Vector([2.118, 4.827])
w = Vector([0, 0])
print('Is orthogonal: ', v.is_orthogonal_to(w), 'Is parallel: ', v.is_parallel_to(w))

v = Vector([7.887, 4.138])
w = Vector([-8.802, 6.776])
print(v.dot_product(w))

v = Vector([-5.955, -4.904, -1.874])
w = Vector([-4.496, -8.755, 7.103])
print(v.dot_product(w))

v = Vector([3.183, -7.627])
w = Vector([-2.668, 5.319])
print(v.angle(w))

v = Vector([7.35, 0.221, 5.188])
w = Vector([2.751, 8.259, 3.985])
print(v.angle(w, in_degrees=True))

v = Vector([-0.221, 7.437])
print(v.magnitude())

v = Vector([8.813, -1.331, -6.247])
print(v.magnitude())

v = Vector([5.581, -2.136])
print(v.normalized())

v = Vector([1.996, 3.108, -4.554])
print(v.normalized())

v = Vector([8.218, -9.341])
w = Vector([-1.129, 2.111])
print(v.plus(w))

v = Vector([2, 2])
w = Vector([2, 2])
print(v.minus(w))

v = Vector([1.671, -1.012, -0.318])
c = 7.41
print(v.times_scalar(c))

my_vector = Vector([1,2,3])
my_vector2 = Vector([1,2,3])
my_vector3 = Vector([-1,2,3])

print(my_vector)
print(my_vector==my_vector2)
print(my_vector==my_vector3)
"""
