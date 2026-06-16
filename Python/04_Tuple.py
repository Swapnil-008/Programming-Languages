# Tuples:
# A built in data type that lets us create "immutable" sequences of values

tup = (10, 20, 30, 40, 20)
print(tup)
print(type(tup))
# Since tuples are immutable built in data type we can't perform assignment opperations on it
# tup[0] = 20  --> It generates error
# tup = (20,)  # single element tupple, but if we missed that ',' then it will be considered as a single integer value stored in tup, and that's why type of tup will be integer
# print(tup) 
# print(type(tup))

# Tuple methods:
# Tuple slicing is same as List Slicing

print(tup.index(20)) # returns index of first occurrence
print(tup.count(20)) # counts total occurrences
