# Model 1 - function for calculating the volume of the resorvoar by using a rectangle

x = 2050 # Width of the base in foot
y = 2200 # Length of the base in foot
vertical_depth = 2 + 8 # freeBoard depth + vertical wall depth
volume = x * y * vertical_depth # initial volume for vertical depth
layers = int(input("Enter number of layers to calculate the volume: ")) 
sloped_depth = (94-10) # (total depth - vertical_depth)
layer_height = sloped_depth / layers 
# Adjust x and y for the initial layer at the start of the slope
x -= 1.3*(1/2 * layer_height) 
y -= 1.3*(1/2 * layer_height)

for i in range(layers):
    volume += x * y * layer_height
    x -= 1.3 * layer_height
    y -= 1.3 * layer_height

print(f"The total volume of the resourvair using one rectangular shape: {volume:.3f} cubic feet") 