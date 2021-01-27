#########
#NOTES TO SOLVE THE ISSUE BELOW
########

"""
We have the following info:

A = cancer
B = positive


P(A) = 0.2
P(B|A) = 0.9
P(<B|<A) = 0.5

Thus:
P(<A) = 0.8
P(<B|A) = 0.1
P(B|<A) = 0.5

We want P(A|B)!, so we must find P(B,A) and normalizer

Joints are:
P(B,A) = P(A) * P(B|A) = 0.2 * 0.9 = 0.18
P(B,<A) = P(<A) * P(B|<A) = 0.8 * 0.5 = 0.4

Normalizer = 0.58

P(A|B) = P(B,A) / norm = 0.18/0.58
"""

# Given three input probabilities, complete this function
# so that it returns the posterior probability

def bayes(p_A, p_B_given_A, p_notB_given_notA):

    ## TODO: Calculate the posterior probability
    ## and change this value
    joint1 = p_A * p_B_given_A
    joint2 = (1-p_A) * (1-p_notB_given_notA)

    norm = joint1 + joint2

    posterior = joint1 / norm

    return posterior


## TODO: Change these values, run your code with them, and use print
## statements to see the output of your function and get feedback
p_A = 0.3
p_B_given_A = 0.7
p_notB_given_notA = 0.9

posterior = bayes(p_A, p_B_given_A, p_notB_given_notA)
print('Your function returned that the posterior is: ' + str(posterior))

#TEST CELL

test_p_A = 0.4
test_p_B_given_A = 0.7
test_p_notB_given_notA = 0.9

# This line calls your function and stores the output
posterior = bayes(test_p_A, test_p_B_given_A, test_p_notB_given_notA)
correct_posterior = bayes(test_p_A, test_p_B_given_A, test_p_notB_given_notA)

# Assertion, comparison test
try:
    assert(abs(posterior - correct_posterior) < 0.0001)
    print('That\'s right!')
except:
    print ('Your code returned that the posterior is: ' +str(posterior)
           + ', which does not match the correct value.')
