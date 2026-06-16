class Employee:
    def __init__(self, role, department, salary):
        self.role = role
        self.department = department
        self.salary = salary
    
    def showInfo(self):
        print("---------- Employee ----------")
        print("Role:", self.role)
        print("Department:", self.department)
        print("Salary:", self.salary)


class Engineer(Employee):
    def __init__(self, role, department, salary, name, age):
        super().__init__(role, department, salary)
        self.name = name
        self.age = age
    
    def showInfo(self):  # Overriding
        super().showInfo()   # Call parent method
        print("Name:", self.name)
        print("Age:", self.age)


eng1 = Engineer("Software Developer", "IT", 75000, "Swapnil", 22)
eng2 = Engineer("Technical Lead", "CS", 200000,"Amey", 21)

# eng1.showInfo()
# eng2.showInfo()

# Overload a greater than '>' operator to compare the price of different orders

class Order:
    def __init__(self, item, price):
        self.item = item
        self.price = price

    def __gt__(self, item2):
        return self.price > item2.price
    
order1 = Order("Eggs", 42)
order2 = Order("Banana", 35)

# print(order1 > order2) # True

# Guess the number

import random

# Generating random integer to guess
"""
start = int(input("Enter start: "))
end = int(input("Enter end: "))
randomNumber = random.randint(start, end)
validChances = 10
remainingChances = validChances
print("Correct number is between", start, "and", end)
while(True):
    if(remainingChances == 0):
        print("Your chances are finished to guess the correct number.")
        print("The correct number was:", randomNumber)
        break

    print("You have", remainingChances, "remaining chances to guess the number correct!")
    guessedNum = int(input("Guess the num: "))
    remainingChances -= 1
    if(guessedNum == randomNumber):
        print("Your guess is correct, number is:", guessedNum)
        print("You used", validChances - remainingChances, "turns to guess the correct number...")
        print("--------- Game Over ---------")
        break
    elif(guessedNum < randomNumber):
        print("Your guess is less than the correct number")
    else:
        print("Your guess is greater than the correct number")

"""
import string
# Random password generator

validCharacters = string.ascii_uppercase + string.ascii_lowercase + string.digits + string.punctuation

passwordLength = int(input("Enter length of password required: "))
randomPassword = ""

for i in range(passwordLength):
    randomPassword += random.choice(validCharacters)

print("Generated random password:", randomPassword)