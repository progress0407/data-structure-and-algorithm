# Define the changes in y and x coordinates for all 8 directions
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

# Initialize starting position
y, x = 0, 0

# Iterate through all directions and calculate the new positions
for i in range(8):
    ny = y + dy[i]
    nx = x + dx[i]
    print(f"{ny} : {nx}")