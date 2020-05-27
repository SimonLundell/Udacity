my_list = [1, 2, 3, "a", "b", "c"]

print("Enumerating a list...")

for i, item in enumerate(my_list):

    print("item number", i, "is", item)

    
"""
Enumerating a list...
item number 0 is 1
item number 1 is 2
item number 2 is 3
item number 3 is a
item number 4 is b
item number 5 is c
"""

print("Another way to enumerate using a list 'method'...")

for item in my_list:

    index = my_list.index(item)

    print("item", item, "has index", index)

"""
Another way to enumerate using a list 'method'...
item 1 has index 0
item 2 has index 1
item 3 has index 2
item a has index 3
item b has index 4
item c has index 5
"""

# The preferred 'pythonic' way to create a list
numbers_0_to_9 = [x for x in range(10)]
print("Numbers 0 to 9", numbers_0_to_9)

# You can also choose to do computation / flow control when generating
# lists
squares = [x * x for x in range(10)]
print("Squares       ", squares)

# note - this example uses the "modulo" operator
odds = [x for x in range(10) if x % 2 == 1]
print("Odds          ", odds)

# Import the module collections and be able to access namedtuple
# wihtout having to write collections.namedtuple each time.
from collections import namedtuple
# Create a tuple of class 'Person'
Person = namedtuple("Person", ["name", "age", "gender"])

# Build a list of people by using Person
people = [
    Person("Andy", 30, "m"),
    Person("Ping", 1, "m"),
    Person("Tina", 32, "f"),
    Person("Abby", 14, "f"),
    Person("Adah", 13, "f"),
    Person("Sebastian", 42, "m"),
    Person("Carol" , 68, "f"),
]

# first, let's show how this namedtuple works.
# Get the first entry in the list (which is Andy from above)
andy = people[0]

# From here, you can access andy like it was a class with attributes
# name, age, and gender (as seeon from the namedtuple)
print("name:  ", andy.name)
print("age:   ", andy.age)
print("gender:", andy.gender)

# now let's show what we can do with a list comprehension
male_names = [person.name for person in people if person.gender=="m"]
print("Male names:", male_names)

# Create a list of names where there age
teen_names = [p.name for p in people if 13 <= p.age <= 18 ]
print("Teen names:", teen_names)
