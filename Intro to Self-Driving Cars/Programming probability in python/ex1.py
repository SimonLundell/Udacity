def probability_uniform(low_range, high_range, minimum, maximum):
    
    ## TODO: Calculate the probability of an event occurring 
    ## between low_range and high_range.
    ## Assume the user has given valid inputs such that low_range < high_range.
    ##   minimum < maximum
    ##
    
    
    probability = (high_range - low_range) / (maximum - minimum)
    
    return probability
   
## TODO: Test your results by running this cell.
## If the cell produces no output, your answer was as expected

assert "{0:.2f}".format(probability_uniform(15, 305, 0, 360)) == '0.81'
assert "{0:.2f}".format(probability_uniform(1, 5, 0, 10)) == '0.40'
assert "{0:.2f}".format(probability_uniform(55, 70, 20, 300)) == '0.05'
print('Great work! Your code outputs the expected results.')
