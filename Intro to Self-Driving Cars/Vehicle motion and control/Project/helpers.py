import pickle

def process_data(filename):
    with open(filename, 'rb') as f:
        data_list = pickle.load(f)
        print data_list
    return list(data_list)
