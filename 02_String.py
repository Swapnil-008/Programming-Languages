# Escape sequence characters:
# '\n' -> generates the new line
# '\t' -> adds the space bar
# str = "There is something hidden behind that wall.\nDon't \t you think?"
# print(str)

# Concatenation
str1 = "Hello"
str2 = " World"
print("Concatenation:", str1 + str2)

# Length
print("Length:", len(str1 + str2))

# Indexing
# Python follows 0 based indexing
# print("0th Character:", str[0])
# Using indexing, we can only access characters of string, but we can't modify them
# Because strings are immutable in python, meaning their value can't be changed after creatiom
# str[2] = 's'  -> It will generate error

# Slicing -> Accessing parts of a string
# str[starting_index : ending_index] -> ending_index is not included
# print(str[0 : 5])
# print(str[0 : 5]) and print(str( : 5)) both are same
# print(str[0 : len(str)]) and print(str[0 : ]) both are same

# Negative Indexing: 
# A  P  P  L  E
# 0  1  2  3  4  -> Positive Indexing
#-5 -4 -3 -2 -1  -> Negative Indexing

# str = "APPLE"
# print(str[-5 : -2])
# Built-in functions of a string doesn't make change in the original string
# str = "i am a coder."
# print(str.endswith("er."))  --> Returns true if string ends with passed substring
# print(str.capitalize())  # Capitalizes the first character of a string

# print(str.replace("a", "@")) # Replaces all occurances of first passed parameter string to second passed parameter string

# print(str.find("a"))  # Returns first occurance of a substring inside the string, -1 for not found

# print(str.count("a")) # Returns count of occurance of a substring

# Find greatest number among three numbers
"""
num1 = int(input("Enter num1: "))
num2 = int(input("Enter num2: "))
num3 = int(input("Enter num3: "))

greatest = num1

if(num2 > greatest):
    greatest = num2

if(num3 > greatest):
    greatest = num3

print(greatest, "is the greatest among", num1, num2, num3)
"""