import re
import string
from datetime import datetime

def CurrentDate():
    now = datetime.now()
    date = now.strftime("%m/%d/%Y")
    return date

# fuction to show items in txt file and their frequency.
def ItemsPurchased():
    # opening file
    with open('ItemsPurchased.txt', 'r') as myFile:
        lines = []
        for line in myFile:
            lines.append(line.strip())

    myFile.close() # closing file

    # graphical representation formated.
    print("\n\n")
    print("=" * 40)
    print("{}{:<19}{:>19}{}".format("*", "Item list*", "*Times Shown", "*"))
    print("=" * 40)
        
    itemList = []
    count = 0
    
    # for loop to append items read into a list then display to user
    for i in lines:
        item = ""
        if i not in itemList:
            item = i            
            for j in lines:           
                if j == i:
                    count += 1
            itemList.append(item)

            print("{} {:.<32}{:.>4} {}".format("=", item, count, "="))
        
        count = 0

    print("=" * 40, '\n')           
    

    return

# take input from user and show specific item and its frequency
def ItemPurchased(item):
    itemList = {} # using dictionary to store both item and its frequency
    count = 0

    with open('ItemsPurchased.txt', 'r') as myFile:
        lines = []
        for line in myFile:
            lines.append(line.strip())

    # print("\n", "Produce List: ", "\n")        
    # print(", ".join(lines))
    myFile.close()

    print("\n")
    print("=" * 40)
    print("{}{:<19}{:>19}{}".format("*", "Item Purchased*", "*Times Purchased", "*"))
    
    for i in lines:
        if i == item:
            count += 1
    itemList[item] = count

    print("=" * 40)           

    return count # returns the count on an item

# function to show a histogram after reading from a file.
def Histogram():
    with open('ItemsPurchased.txt', 'r') as myFile:
        lines = []
        for line in myFile:
            lines.append(line.strip())

    myFile.close()

    print("\n\n")
    print("=" * 40)
    print("{}{:<19}{:>19}{}".format("*", "Item Purchased*", "*Times Purchased", "*"))
    print("=" * 40)
        
    itemList = {}
    count = 0
    
    # reading from file
    for i in lines:
        item = ""
        if i not in itemList:
            item = i            
            for j in lines:           
                if j == i:
                    count += 1
                itemList[item] = count

            print("{} {:.<32}{:.>4} {}".format("=", item, count, "="))
        
        count = 0

    print("=" * 40, '\n')   
    
    # writing to file
    with open('frequency.dat', 'w') as myFile2:
        count2 = 0
        for i in itemList:
            myFile2.write("{} {}\n".format(i, itemList[i]))
    
    myFile2.close()
    
    print("Frequency.dat has been created \n")

    return 0



    
