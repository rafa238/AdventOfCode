import re
cont = 0
lista = [1,]
with open("input.txt") as file:
    for line in file:
        last_element = lista[-1]  
        if line.startswith("addx"):
            _ , x = line.split(" ")
                      
            lista.append(last_element)
            lista.append(last_element + int(x))
        else:
            lista.append(last_element)
sum = 0
queries =  [20, 60, 100, 140, 180, 221]
for elem in queries:
    sum += elem*lista[elem]
print(sum)
