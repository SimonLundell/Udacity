# Import the random module and reference it as rd
import random as rd


def simulate_dice_rolls(N):
    """
    Simulates dice rolls
    
    Args:
        N (int): The number of trials
        
    Returns:
        list: roll counts [1,6]
    """
    # Create a list to track the 6 options for the roll
    roll_counts = [0,0,0,0,0,0]
    for i in range(N):
        # Randomly select a value from the list (1 to 6)
        roll = rd.choice([1,2,3,4,5,6]) 
        # Recall indices start at 0 so we need to decrement
        index = roll - 1
        roll_counts[index] = roll_counts[index] + 1
    return roll_counts

def show_roll_data(roll_counts):
    """
    Shows the dice roll data
    
    Args:
        roll_counts (list): The roll counts stored in the list
        
    Returns:
        list: roll counts [1,6]
    """ 
    # Gets the number of sides of the dice and prints
    # the side of the die. 
    # enumerate creates the position of the die and the
    # list value
    for dice_side, frequency in enumerate(roll_counts):
        print(dice_side + 1, "was rolled", frequency, "times")
        
roll_data = simulate_dice_rolls(1000)
show_roll_data(roll_data)

# Matplotlib is one of the most common plotting packages in Python
# to use it more succinctly, you can call it
from matplotlib import pyplot as plt
# This line is needed
#%matplotlib inline

def visualize_one_die(roll_data):
    """
    Visualizes the dice rolls

    Args:
        roll_data (int): roll counts in a list from [1,6]

    Returns:
        None - shows a plot with the x-axis is the dice values
               and the y-axis as the frequency for t
    """
    roll_outcomes = [1,2,3,4,5,6]
    fig, ax = plt.subplots()
    ax.bar(roll_outcomes, roll_data)
    ax.set_xlabel("Value on Die")
    ax.set_ylabel("# rolls")
    ax.set_title("Simulated Counts of Rolls")
    plt.show()

roll_data = simulate_dice_rolls(500)
visualize_one_die(roll_data)
