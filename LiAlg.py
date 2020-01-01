class Vector(object):
    # Creates vector based on an input list of coordinates and also sets the dimensions of the space
    # that the vector lives in.
    def __init__(self, coordinates):
        try:
            if not coordinates:
                raise ValueError
            self.coordinates = tuple(coordinates)
            self.dimension = len(coordinates)

        except ValueError:
            raise ValueError('The coordinates must be nonempty')

        except TypError:
            raise TypeError('The coordinates must be an iterable')

    def plus(self, v):
        new_coordinates = [x+y for x,y in zip(self.coordinates, v.coordinates)]
        return new_coordinates

    def minus(self, v):
        new_coordinates = [x-y for x,y in zip(self.coordinates, v.coordinates)]
        return new_coordinates
    
    def times_scalar(self, c):
        new_coordinates = [c*x for x in self.coordinates]
        return Vector(new_coordinates)
    
    def __str__(self):
        return 'Vector: {}' .format(self.coordinates)

    def __eq__(self, v):
        return self.coordinates == v.coordinates

v = Vector([8.218, -9.341])
w = Vector([-1.129, 2.111])
print(v.plus(w))

v = Vector([7.119, 8.215])
w = Vector([-8.223, 0.878])
print(v.minus(w))

v = Vector([1.671, -1.012, -0.318])
c = 7.41
print(v.times_scalar(c))

#my_vector = Vector([1,2,3])
#my_vector2 = Vector([1,2,3])
#my_vector3 = Vector([-1,2,3])

#print(my_vector)
#print(my_vector==my_vector2)
#print(my_vector==my_vector3)

#Testing some stuff
