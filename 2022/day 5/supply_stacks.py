with open("input.txt") as f:
    lines = f.readlines()

#PART 1
    
#break moves directions into a list of lists
movesList = [x.split() for x in lines[10:]]

bigList = []
for each in lines[:8]:
    smallList = [each[x:x + 4].split() for x in range(0, len(each), 4)]
    newList = []
    for y in smallList:
        if len(y) == 0:
            newList.append("0")
        else:
            newList.append(y[0][1])   
    bigList.append(newList)
for each in bigList:
    print(each)

for each in movesList:
    #print(each)
    num = int(each[1]) #number of crates to move
    org = int(each[3]) #origin
    dest = int(each[5]) #destination
    
    for i in range(num): #do it for number of moves
        num_rows = len(bigList)
        j=0 #row to grab from
        #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        while bigList[j][org-1] == '0':
            j+=1
        letter = bigList[j][org-1] #getting the letter for the crate we are moving
        bigList[j][org-1] = '0' #replacing the crate we are moving with a zero
        
        k=0 #row to move to
        #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        if bigList[k][dest-1] != '0': #if there is a crate already in the top row
            newRow = [] #make a brand new row to put on top with a crate in that column
            for a in range(len(bigList[0])):
                if a == dest-1:
                    newRow.append(letter)
                else:
                    newRow.append('0')
            newList = []
            newList.append(newRow)
            for each in bigList:
                newList.append(each)
            bigList = newList
            
        else: #if there is not a crate already in the top row
            while k<=num_rows-1 and bigList[k][dest-1] == '0': #check down all rows with condition for if all rows are '0'
                k+=1

            if k == num_rows+1 and bigList[k][dest-1] == '0': #scenario where stack has no crates --> put crate on bottom
                bigList[k][dest-1] = letter
            
            else: #we've found a crate (non-zero) in the stack so we want to put the moved crate one row up from current top
                bigList[k-1][dest-1] = letter
            
        #clear out zero rows at top (if any)
        zero = True
        for b in range(len(bigList[0])):
            if bigList[0][b] != '0':
                zero=False
        if zero == True: #entire top row is zero
            bigList = bigList[1:]
        
#find top letter in each row
letterList = []
for c in range(len(bigList[0])):
    j=0 #row to grab from
    while bigList[j][c] == '0': #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        j+=1
    letter = bigList[j][c]
    letterList.append(letter)
print(letterList)

aStr = ''
for each in letterList:
    aStr+=each
print(aStr) 


#PART 2
#break moves directions into a list of lists
movesList = [x.split() for x in lines[10:]]

bigList = []
for each in lines[:8]:
    smallList = [each[x:x + 4].split() for x in range(0, len(each), 4)]
    newList = []
    for y in smallList:
        if len(y) == 0:
            newList.append("0")
        else:
            newList.append(y[0][1])   
    bigList.append(newList)
for each in bigList:
    print(each)

for each in movesList:
    #print(each)
    num = int(each[1]) #number of crates to move
    org = int(each[3]) #origin
    dest = int(each[5]) #destination  

    num_rows = len(bigList)
    j=0 #row to grab from
    while bigList[j][org-1] == '0': #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        j+=1
        
    for i in range(num): #Looping through number of times for number of crates needed to be moved
        letter = bigList[j+num-i-1][org-1] #getting the letter for the crate we are moving, starting at bottom of stack we're moving
        bigList[j+num-i-1][org-1] = '0' #replacing the crate we are moving with a zero

        k=0 #row to move to
        #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        if bigList[k][dest-1] != '0': #if there is a crate already in the top row
            num+=1 #have to add one for the purposes of tracking row for rest of movement
            newRow = [] #make a brand new row to put on top with a crate in that column
            for a in range(len(bigList[0])):
                if a == dest-1:
                    newRow.append(letter)
                else:
                    newRow.append('0')
            newList = []
            newList.append(newRow)
            for each in bigList:
                newList.append(each)
            bigList = newList
        else: #if there is not already a crate in the top row
            while k<=num_rows-1 and bigList[k][dest-1] == '0': #check down all rows with condition for if all rows are '0'
                k+=1

            if k == num_rows+1 and bigList[k][dest-1] == '0': #scenario where column has no values --> put crate on bottom
                bigList[k][dest-1] = letter
                
            else: #we've found a crate (non-zero) in the stack so we want to put the moved crate one row up from current top
                bigList[k-1][dest-1] = letter

    #clear out zero rows at top (if any)
    zero = True
    for b in range(len(bigList[0])):
        if bigList[0][b] != '0':
            zero=False
    if zero == True: #entire top row is zero
        bigList = bigList[1:]
        
    #for each in bigList:
        #print(each)
    #print('\n')

#find top letter in each row
letterList = []
for c in range(len(bigList[0])):
    j=0 #row to grab from
    while bigList[j][c] == '0': #starting at top, find first row with a nonzero entry (aka the highest crate in the stack)
        j+=1
    letter = bigList[j][c]
    letterList.append(letter)
#print(letterList)

aStr = ''
for each in letterList:
    aStr+=each
print(aStr)