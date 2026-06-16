# Loops
# Loops are used to repeat instructions

# while loop:
# Syntax -> while(condition):
                # work
"""
count = 0
while(count < 5):
    print("Hello", count)
    count += 1
"""
# Search for a number x in list using loop
list1 = [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
target = 101
i = 0
# while(i < len(list1)):
#     if(list1[i] == target):
#         print(target, "Found")
#         break
#     i += 1

# if(i == len(list1)):
#     print(target, "Not found")

# These usually used inside some condition
# break: used to terminate the loop when encountered
# continue: Skips the current iteration and continues execution of the loop with the next iteration

# for loop:
# Syntax -> for element in list:
                # some work
# for element in list1:
#     print(element)

# if we want to do some work on completion of loop iterations we can use for loop with else
# Below example defines, if element not found until the complete loop gets iterated, means element not found -> which does the else statement
# for x in list1:
#     if(x == target):
#         print(target, "found")
# else:
#     print(target, "not found")

# range()
# range function returns sequence of numbers, starting from 0 by default, and increments by 1(by default), and stops before a specified number
# range(start?, stop, step?)  ? -> shows optional
# range(5)  0 -> 4
# range(2, 5)  2 -> 4
# range(1, 7, 2) -> 1, 3, 5

# for i in range(0, 10, 2):
#     print(i)