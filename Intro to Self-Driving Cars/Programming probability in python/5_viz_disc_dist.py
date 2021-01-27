import matplotlib.pyplot as plt

def bar_heights(intervals, relative_probabilities, total_probability):

    heights = []
    
    #TODO: sum the relative probabilities
    total_relative_prob = sum(relative_probabilities)
    
    for i in range(0, len(relative_probabilities)):
        
        #TODO: Looping through the relative_probabilities list, 
        #      take one probability at a time and 
        #      calculate the area of each bar. Think about how you can 
        #      calculate the area of a bar knowing the total_probability,
        #      relative probability, and the sum of the relative probabilities.
        
        #HINT: It's possible to do this in one line of code
        bar_area = total_probability / total_relative_prob * relative_probabilities[i]
        
        # TODO: Calculate the height of the bar and append the value to the
        # heights list. Remember that the area of each bar 
        # is the width of the bar times the height of the bar
        height = bar_area / (intervals[i+1] - intervals[i])
        
        #HINT: It's possible to do this in one line of code
        heights.append(height)
        
    return heights

print(bar_heights([0, 5, 10, 16, 21, 24], [1, 5, 3, 6, 0.5], 0.05))

hour_intervals = [0, 5, 10, 16, 21, 24]
probability_intervals = [1, 5, 3, 6, 1/2]
accident_probability = 0.05

heights = bar_heights(hour_intervals, probability_intervals, accident_probability)

for i in range(len(probability_intervals)):
    plt.plot([hour_intervals[i], hour_intervals[i+1]], [heights[i], heights[i]], color='blue')
    plt.plot([hour_intervals[i], hour_intervals[i]], [0, heights[i]], '--', color='blue')
    plt.plot([hour_intervals[i+1], hour_intervals[i+1]], [0, heights[i]], '--', color='blue')

plt.xticks(range(0,25,1))
plt.xlabel('hours')
plt.ylabel('probability density function')
plt.title('Probability Density Function \n for Car Accidents During the Day')
plt.show()
