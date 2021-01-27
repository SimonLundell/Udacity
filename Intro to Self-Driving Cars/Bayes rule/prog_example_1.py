# The inputs to total probability are given descriptive names

def total_probability(p_disease, p_pos_given_disease, p_pos_given_no_disease):
    
    ## TODO: Change the value of total so that it calculates the 
    ## total probability of a positive test result
    ## You may use other variable in this function as well as long
    ## as total is correct
    total = p_disease * p_pos_given_disease + (1-p_disease) * p_pos_given_no_disease
    
    return total

    
## TODO: Change these test values, run your function, and write print statements to test your code
## Answer the question: what is the probability of a positive test result given the following values?
p_disease = 0.2
p_pos_given_disease= 0.6
p_pos_given_no_disease= 0.6

tot = total_probability(p_disease, p_pos_given_disease, p_pos_given_no_disease)
print('Your function returned that the total probability is: '+str(tot))

# This line calls your function and stores the output
total = total_probability(p_disease, p_pos_given_disease, p_pos_given_no_disease)
correct_total = total_probability(p_disease, p_pos_given_disease, p_pos_given_no_disease)

# Assertion, comparison test
try:
    assert(abs(total - correct_total) < 0.0001)
    print('That\'s right!')
except:
    print ('Your code returned that the total probability is: ' +str(total)
           + ', which does not match the correct value.')
