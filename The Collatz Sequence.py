def collatz(num):
    if num % 2 == 0:
        num = num // 2
        print(num)
        return num
    else:
        num = (num * 3) + 1
        print(num)
        return num

print('enter a number')

while True:
    try:
        userNum = int(raw_input())
        break
    except ValueError:
        print('you didn\'t enter a valid integer')
    
print(userNum)

while True:
    userNum = collatz(userNum)
    if userNum == 1:
        break
