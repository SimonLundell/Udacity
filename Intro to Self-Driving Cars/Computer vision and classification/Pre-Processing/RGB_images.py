import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

image = mpimg.imread('images/wa_state_highway.jpg')

plt.imshow(image)

plt.show()

# Isolate RGB channels
r = image[:,:,0]
g = image[:,:,1]
b = image[:,:,2]

# Visualize the individual color channels
f, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(20,10))
ax1.set_title('R channel')
ax1.imshow(r, cmap='gray')
ax2.set_title('G channel')
ax2.imshow(g, cmap='gray')
ax3.set_title('B channel')
ax3.imshow(b, cmap='gray')

plt.show()

red_area = np.amin(r)
blue_area = np.amin(b)
green_area = np.amin(g)

print("Red min: ", red_area)
print("Blue min: ", blue_area)
print("Green min: ", green_area)

red_loc = np.where(r == red_area)
green_loc = np.where(g == green_area)
blue_loc = np.where(b == blue_area)

print(red_loc[0], red_loc[1])
print(green_loc[0], green_loc[1])
print(blue_loc[0], blue_loc[1])

## Which area has the lowest value for red? What about for blue?
