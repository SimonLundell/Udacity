def probability_range_improved(low_range, high_range, minimum, maximum):

    a = isinstance(low_range, str)
    b = isinstance(high_range, str)
    c = isinstance(minimum, str)
    d = isinstance(maximum, str)
    
    if (a or b or c or d):
        # print a message to the user and return none
        print('Inputs should be numbers not string')
        return None
    
    # TODO check that low_range is between minimum and maximum
    if not (minimum < low_range < maximum):
        # print a message to the user and return none
        print('Your low range value must be between minimum and maximum')
        return None
        
    # TODO check that high_range is between min and max
    if not (minimum < high_range < maximum):
        # print a message to the user and return none
        print('The high range value must be between minimum and maximum')
        return None
    
    tot_range = abs(high_range - low_range)
    tot_value = abs(maximum - minimum)
    probability = tot_range / tot_value
    
    return probability

assert probability_range_improved('a', 0, -100, 500) == None
assert probability_range_improved(0, 'b', -100, 500) == None
assert probability_range_improved(-100, 300, 100, 500) == None
assert probability_range_improved(105, 700, 100, 500) == None
#assert "{0:.2f}".format(probability_range_improved(25, 700, 5, 800)) == '0.85' These 2 doesnt work outside webpage
#assert "{0:.2f}".format(probability_range_improved(700, 25, 5, 800)) == '0.85'
print('You got the results we were looking for!')


"""
Example solve:

    def probability_range_improved(low_range, high_range, minimum, maximum):

    if (isinstance(low_range, str) or isinstance(high_range, str)):
        # print a message to the user and return none
        print('Inputs should be numbers not string')
        return None

    if (low_range < minimum or low_range > maximum):
        # print a message to the user and return none
        print('Your low range value must be between minimum and maximum')
        return None

    if (high_range < minimum or high_range > maximum):
        # print a message to the user and return none
        print('The high range value must be between minimum and maximum')
        return None

    probability = abs(high_range - low_range) / (maximum - minimum)

    return probability

"""
