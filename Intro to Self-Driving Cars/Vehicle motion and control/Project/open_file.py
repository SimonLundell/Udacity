import pickle

"""
with open("trajectory_example.pickle", "rb") as f:
    for line in f:
        data = list(pickle.load(f))
"""

infile = open("trajectory_example.pickle", 'rb')
new_dict = pickle.load(infile)
infile.close()

print new_dict

