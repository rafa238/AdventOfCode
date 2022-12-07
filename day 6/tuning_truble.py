with open("input.txt") as f:
    line = f.readline()

def sliding_window(size:int):
    for i in range(len(line) - size + 1):
        unrepeated = set({x for x in line[i: i+size]})

        if len(unrepeated) == size:
            print(i+size)
            break

#part 1
sliding_window(4)

#part 2
sliding_window(14)