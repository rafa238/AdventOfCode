# import modules
from collections import defaultdict

# initialise lists
signal = []
cycles = defaultdict(int)
sprites = []

# define variables
X = 1
cycle = 1
lit =   '\U0001F7E9'
dark = '\U00002B1B'
output = ''
screen_width = 40

# read input file
with open('input.txt', 'r') as file:
    for line in file:
        signal.append(line.strip())

# run through commands in program
for command in signal:
    cycles[cycle] = X
    
    # noop = continue
    if(command=='noop'):
        cycle += 1
        cycles[cycle] = X
    
    # addx V = wait 2 cycles then add V to X
    elif(command.startswith('addx')):
        V = int(command.split(' ')[-1])
        for i in range(2):
            cycle += 1
            cycles[cycle] = X
        X += V
        cycles[cycle] = X

# save X values as sprites
for(cycle,X) in cycles.items():
    sprites.append(X)

# set CRT screen
for i, value in enumerate(sprites):
    # light pixel if pixel is in range of 3-pixel sprite
    if sprites[i] in range((i % screen_width) - 1, (i % screen_width) + 2):
        output += lit

    # otherwise keep pixel dark
    else:
        output += dark
    
    # at edge of screen add newline
    if (i + 1) % screen_width == 0:
        output += "\n"

# print answer
print(output)