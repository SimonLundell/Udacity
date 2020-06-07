def get_integral_from_data(data, times):
    previous_time = times[0]
    
    accumulated_data = 0.0
    
    results = []
    
    for i in range(1, len(times)):
        delta_time = times[i] - previous_time
        
        delta_data = delta_time * data[i]
        
        previous_time = times[i]
        
        accumulated_data += delta_data

        results.append(accumulated_data)
        
    
    return results
