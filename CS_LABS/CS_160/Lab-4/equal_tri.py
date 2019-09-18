base = int(input('how many stars do you want in the base of your triangle: '))
base = (base + 1)
start = 1
spaces = base

while (base != start):
	print (' ' * spaces, end=' ')
	print ('* ' * start)
	start = (start + 1)
	spaces = (spaces - 1)
