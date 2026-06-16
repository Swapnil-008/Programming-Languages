# Machine doesn't understand the prgramming laguages directly, so the interpreter or compiler converts the code into 0/1 form so that machine could process the code
# Developed by Guido Van Rossum

# Comment - It is a code or text which is ignored by interpreter
# Prints on different lines -> Single line comment
print("Swapnil is my name.")
print("I'm 22 years old")

# Prints on same line
print("Swapnil is my name, ", "I'm 22 years old")
""" -> Multiple  line comment """  

# Python allows to perform arithmetic operations in print function
print(10 + 15)

# Variable is a name given to memory location in a program.
# Only alphabets, digits, and underscore(_) is allowed in identifier or variable name
name = "swap"
age = 23
weight = 62.5
print("name: ", name, "\nAge: ", age, "\nWeight: ", weight)
print(type(name)) # Returns the type of data stored in variable
print(type(age))
print(type(weight))

# Primary data types: Integer, String, Float, Boolean, None
# Punctuators are symbols to organize sentence structure in programming
# Ex. (), {}, [], #, @, etc.

# It is a implicit typed language, no need to mention the type of data implicitly

# String and numeric values can operate together with *
A, B = 2, 3
str1 = "text "
print(2 * str1 * 3)

# String and string can operate with + -> Concatenation
A, B = "text", 3
str1 = "@ "
print((A + str1) * 3)

# Arithmetic expression with Integer and Float will always result in Float
A, B = 10, 3.0
print(A / B)

# Integer division with float and int will give int displayed as float
A, B = 10, 3.0
print(A // B) # It is same floor(A / B), floor gives closest integer, which is lesser than or equal to the float

# Remainder is negative when denomiator is negative
print(10 % -3)
"""
For your example:
    - 10 % -3

First calculate:
    - 10 // -3
    10 / -3 = -3.333...

Flooring that gives:
    [-3.333...]= -4

So:
    10 % -3 = 10 - (-3 * -4)
    = 10 - 12
    = -2
"""

print(2**3)

# Taking input from user

"""
name = str(input("Name: "))
age = int(input("Age: "))
weight = float(input("Weight: "))
isGraduated = bool(input("IsGraduated: "))
print("My name is", name, ", I'm", age, "years old, and my weight is", weight)
if(isGraduated):
    print(name, " is graduated!")
else:
    print(name, " is not graduated yet.")
"""

# Operator precendence in Logical operators: not > and > or

# Conditional Statements
# Indentation must be structured
"""
age = int(input("Age: "))
gender = str(input("Gender (M/F): "))

if(age >= 22 and gender == 'M'):
    print("You have valid age to marry!, so you can marry bastard")
elif(age >= 18 and gender == 'F'):
    print("You have valid age to marry!, so you can marry baby girl")
else:
    print("You are minor, and according to indian goverment laws you can't marry!, so wait for a while, otherwise government will f*ck you!")
"""

# Ternary operator / Single line if
"""
food = str(input("Enter food: "))
eat = "Yes" if food == "cake" else "No"
print("Do you wanna eat:", eat)
"""
# <statement1> if <condition> else <statement2>
"""
food = str(input("Enter food: "))
print("I will eat", food) if food == "cake" or food == "jalebi" else print("I will not eat", food)
"""

# Clever if / Ternary operator - Second method of using ternary operator
# variable (false_val, true_val) [condition]
"""
age = int(input("Enter age: "))
vote = ("No", "Yes") [age >= 18]
print(vote)

food = str(input("Enter food: "))
eat = ("No", "Yes") [food == "cake" or food == "jalebi"]
print("Do you wanna eat: ", eat)
"""

# Simple Interest: P * R * T / 100

# Implicit Typecasting -> Converts the type automatically into superior datatype
# In below example float is a superior datatype
num1 = 5
num2 = 2.5
sum = num1 + num2
print("Sum:", sum) # float 

# Explicit Typecasting -> Converts the type manually
# only str can be concatenated with str not float, that's why it will generate error
"""
a = '20'
b = 10.5
c = a + b
print("c:", c)
"""

# We have explicitly converted the str into int
a = int('20')
b = 10.5
c = a + b
print("c:", c)