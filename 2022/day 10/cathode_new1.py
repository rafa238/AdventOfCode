# import modules
from collections import defaultdict

# initialise lists
signal = []
cycles = defaultdict(int)
signal_strength = {}

# define variables
X = 1
cycle = 1
interesting_cycles = [20,60,100,140,180,220]
total = 0

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

# calculate signal strength
for(cycle,X) in cycles.items():
    signal_strength[cycle] = cycle * X

# find sum of signal strengths
for cycle in interesting_cycles:
    total += signal_strength[cycle]

# print answer
print(total)