###this program says hello an asks for my name.
##
##print('hello world')
##print('what is your name?')
##
##myName = raw_input()
##print('it is good to meet you, ' + myName)
##print('The lenght of your name is: ')
##print(len(myName))
##print('what is your age?')
##myAge = raw_input()
##print('you will be ' + str(int(myAge) + 1) + ' in a year')
##
##if myName == 'robert':
##    print('hello robert')
##    print('how are you?')
##elif myName == 'bob':
##    print('hi bob!')
##else:
##    print('hi stranger')
##
##name = ''
##
##while name != 'your name':
##    print('please type your name')
##    name = raw_input()
##print('thank you')
##
##
##while True:
##    print('please type your name')
##    name = raw_input()
##    if name == 'your name':
##        break
##print('thank you')
##
##
##while True:
##    print('who are you?')
##    name = raw_input()
##    if name != 'rob':
##        continue
##    print('hello rob what is the password?')
##    password = ''
##    password = raw_input()
##    if password == 'password':
##        break
##print('access granted')
##
##for num in range(3):
##    print(str(num))
##
##total = 0
##for num in range(101):
##    total += num
##print(total)
##
##total = 0
##i = 0
##while i < 101:
##    total += i
##    i = i + 1
##print(total)
##
##for i in range(100, -100, -2):
##    print(i)

##import random, sys
##for i in range(10):
##    print(random.randint(1, 10))
##
##while True:
##    print('type exit to exit')
##    response = raw_input()
##    if response == 'exit':
##        sys.exit()
##    print('you typed ' + response)
##
##
##print('type a number')
##spam = int(raw_input())
##if spam == 1:
##    print('hello')
##elif spam == 2:
##    print('howdy')
##else:
##    print('greetings!')

##for i in range(1, 11):
##    print(i)
##
##i = 1
##while i < 11:
##    print(i)
##    i = i + 1
##
##
##def hello():
##    print('howdy')
##    print('hello')
##
##hello()
##hello()
##
##def hello(name):
##    print('hello ' + str(name))
##
##hello('robert')
##hello('al')

##import random
##
##def getAnswer():
##    num = random.randint(1,9)
##    if num == 1:
##        return 'it is certain'
##    elif num == 2:
##        return 'it is decidedly so'
##    elif num == 3:
##        return 'yes'
##    elif num == 4:
##        return 'reply hazy, try again'
##    elif num == 5:
##        return 'ask again later'
##    elif num == 6:
##        return 'concentrate and ask again'
##    elif num == 7:
##        return 'my reply is no'
##    elif num == 8:
##        return 'outlook not so good'
##    elif num == 9:
##        return 'very doubtful'
##
##print(getAnswer())

##def spam():
##    global eggs
##    eggs = 'spam'
##
##eggs = 'global'
##spam()
##print(eggs)
##
##def bacon():
##    eggs = 'bacon'
##
##def ham():
##    print(eggs)
##
##eggs = 42
##print(eggs)
##spam()
##print(eggs)

##def spam(divideBy):
##    try:
##        return 42 / divideBy
##    except ZeroDivisionError:
##        print('error: invalid argument')
##        
##print(spam(2))
##print(spam(12))
##print(spam(0))
##print(spam(1))

##def spam(num):
##    return 42 / num
##
##try:
##    print(spam(20))
##    print(spam(10))
##    print(spam(0))
##    print(spam(2340))
##except ZeroDivisionError:
##    print('error: invalid argument')
##
##


##
###this is a guess the number game.
##import random
##secretNum = random.randint(1,20)
##
##print('i\'m thinking of a number between 1 and 20.')
##
###ask player to guess 6 times
##for guessesTaken in range(0,6):
##    print('take a guess')
##    guess = int(input())
##
##    if guess < secretNum:
##        print('your guess is too low')
##    elif guess > secretNum:
##        print('your guess is too high')
##    else:
##        break
##
##if guess == secretNum:
##    print('good job. you took ' + str(guessesTaken) + 'guesses.')
##else:
##    print('nope. the number i was thinking of was ' + str(secretNum))
##
##    
##


##supplies = ['pens', 'pencils', 'notebooks', 'binders']
##for i in range(len(supplies)):
##    print(supplies[i])
##
##
##myPets = ['bob', 'carl', 'david', 'eric']
##print('enter a pet name: ')
##name = raw_input()
##
##if name not in myPets:
##    print('i do not have a pet named ' + name)
##else:
##    print(name + ' is my pet.')
##
##    

##spam = ['apples','bananas','tofu','cats','dog','bird','apples']
##
##def commaCode(someList):
##    myString = ''
##    for i in range(len(someList)):
##        if i == (len(someList) - 1):
##            myString += 'and ' + someList[i]
##            break
##        myString += someList[i] + ', '
##    return myString
##
##print(commaCode(spam))


##from __future__ import print_function
##
##grid = [['.', '.', '.', '.', '.', '.'],
##        ['.', 'O', 'O', '.', '.', '.'],
##        ['O', 'O', 'O', 'O', '.', '.'],
##        ['O', 'O', 'O', 'O', 'O', '.'],
##        ['.', 'O', 'O', 'O', 'O', 'O'],
##        ['O', 'O', 'O', 'O', 'O', '.'],
##        ['O', 'O', 'O', 'O', '.', '.'],
##        ['.', 'O', 'O', '.', '.', '.'],
##        ['.', '.', '.', '.', '.', '.']]
##
##
##for x in range(6):
##    for y in range(9):
##        print(grid[y][x], end='')
##    print()
##    

##import pprint
##
##def displayInventory(inventory):
##    print('Inventory:')
##    numItems = 0
##    for i, j in inventory.items():
##        print(str(j) + ' ' + str(i))
##        numItems += j
##
##    print('number of items = ' + str(numItems))
##
##
##myInventory = {'rope': 1, 'torch': 6, 'gold coin': 42, 'dagger': 1, 'arrow': 12}
##        
##displayInventory(myInventory)
##
##
##def addToInventory(inventory, addedItems):
##    for i in range(len(addedItems)):
##        if addedItems[i] in inventory.keys():
##            inventory[addedItems[i]] += 1
##        else:
##            inventory[addedItems[i]] = 1
##                      
##inv = {'gold coin': 42, 'rope': 1}
##dragonLoot = ['gold coin', 'dagger', 'gold coin', 'gold coin', 'ruby']
##addToInventory(inv, dragonLoot)
##displayInventory(inv)


##print(''' Hello,
##
##This is a multiline string.
##
##    Tabs, newlines
##    and 'quotes" are considered part of it.
##
##''')
##
##
##'''if you want
##to
##write
##
##multiline comments
##
##just use a multiline string'''



