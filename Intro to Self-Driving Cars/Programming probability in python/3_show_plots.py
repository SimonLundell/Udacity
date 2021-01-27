import matplotlib.pyplot as plt
#%matplotlib inline

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

plt.scatter(x, y)
plt.xlabel('x values')
plt.ylabel('y values')
plt.title('X values versus Y values')
plt.xticks([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
plt.show()

"""
Explanation of the Code

import matplotlib.pyplot as plt

The import statement makes the matplotlib library available to your program. 'as plt' means that we can refer to the library as plt instead of by its full name.

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

Here we assign values to be plotted. If you think in terms of (x, y), then the points would be (1, 2) then (2, 4) then (3, 6), etc. However, matplotlib expects the x values and y values to be in separate lists.

plt.scatter(x, y)

The plt.scatter(x,y) line tells Python to create a scatter plot.

plt.xlabel('x values')
plt.ylabel('y values')
plt.title('X values versus Y values')

These lines put labels on the x-axis, y-axis and gives the chart a title.

plt.xticks([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11])

This line manually sets the x-tick marks.

plt.show()

And finally, plt.show() outputs the chart
"""


x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

plt.bar(x, y)
plt.xlabel('x values')
plt.ylabel('y values')
plt.title('X values versus Y values')
plt.xticks([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
plt.show()


x = ['apples', 'pears', 'bananas',
     'grapes', 'melons', 'avocados', 'cherries', 'oranges', 'pumpkins',
    'tomatoes']
y = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

plt.bar(x, y)
plt.xlabel('x values')
plt.ylabel('y values')
plt.title('X values versus Y values')
plt.xticks(rotation=70)
plt.show()


x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

plt.plot(x, y)
plt.xlabel('x values')
plt.ylabel('y values')
plt.title('X values versus Y values')
plt.xticks([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
plt.show()
