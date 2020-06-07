def f2(t):
    return 3*t**3 - 4*t

def integral2(f, t1, t2, dt = 0.0001):
    t = t1
    area = 0.0
    
    while t < t2:
        dA = dt * f(t)
        area += dA
        t += dt
    
    return area

print(integral2(f2, -2, 2))
