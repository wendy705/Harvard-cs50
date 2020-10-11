from cs50 import get_int

#asks for user input until it receives a valid one
height = 0
while (height > 8 or height < 1):
    height = get_int("Height:\n")

#prints a pyramid of as many hashes as indicated by the user
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * (i))