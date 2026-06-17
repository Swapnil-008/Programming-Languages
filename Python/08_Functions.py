# Functions:
# Block of statements that perform a specific task
# It is used to reduce the redundancy and increase the reusability of a code

def sum(a, b): # function defination with parameters
    return a + b

# print(sum(10, 15)) # function call -> function_name(argument1, argument2)
# print(sum(20, 25))
# print(sum(30, 35))
# print(sum(40, 45))
# Types of functions: Built-in functions and User defined functions

# Built-in functions: Functions provided by python
# By-default 'end' for print function is \n, but if want to modify it, we can modify it by specifying the parameter
# print("Swap", end=" ")
# print("Yo Yo")  # now this comes on same line

# User defined functions: Functions defined by user

# Default Parameters: Assigning a default value to parameter, which is used when no argument is passed
def calMult(a, b = 11):  # default parameters must be in last of function defination
    return a * b

# print(calMult(10))

def printList(list):
    for x in list:
        print(x, end=" ")

# printList(list1)

def factorial(num):
    fact = 1
    for i in range(1, num + 1):
        fact *= i
    return fact

print(factorial(5))

# Recursion:
# When a function calls itself repeatedly

# printing numbers recursively
def printRecursive(n):
    if(n == 0):     # base case
        return
    print(n, end=" ")
    printRecursive(n - 1)

printRecursive(10)
print()

# printing numbers while backtracking
def printBacktrack(n):
    if(n == 0):
        return
    printBacktrack(n - 1)
    print(n, end=" ")

printBacktrack(10)
print()

# calculating factorial using recursion
def calc_fact(num):
    if(num == 0 or num == 1):
        return 1
    return num * calc_fact(num - 1)

print(calc_fact(5))

# calculating fibonacci using recursion
def calc_fibo(num):
    if num <= 2:
        return 1
    return calc_fibo(num - 1) + calc_fibo(num - 2)

print(calc_fibo(5))