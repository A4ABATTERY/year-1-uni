print ("Evaluated Expressions")
print (4 / 3 / 2)
print (4 / 3.0 / 2)
print (1 * 2 * 8.0)
print (5 * 10 / 2 + 10 / 5.0)
print ( 2 * 3 / 5 + 8 + 2 + 3)
print ((3 + 2) * 4 / (5 + 8) + 2)
print ((3 + 2) * 4 / 5 + (8 + 2))
print (20.0 / 4 * 2 ** 3)
print (5.5 * 2 + 4 / 2)
print (False and True)
print (not False)
print (True or False)
print (not True or False and False or True)
print (not ((True or False) and (False or True)))
print (not True and False)
print (not (True and False))
print (False and not False or True)

print ("Expressions using variables")
a = (0.0)
b = (1.0)
c = (True)
d = (False)
print (b - a / 10)
print ((b - a)/10)
print ((not c) or (not d))

print ("My name in ASCII")
print (chr(65) + chr(114) + chr(117) + chr(110) + chr(97) + chr(118) +chr(32) + chr(66) + chr(105) + chr(115) + chr(119) + chr(97) + chr(115))


print ("")
print ("Will the sphere sink of float?")
print("")

radius = int(input("Enter a radius (in feet) for your sphere:"))
print ("")
print ("Cool")
print ("")
weight = int(input("Enter a weight (in pounds) for your sphere:"))
print ("")
print ("Awesome")
print ("")
Volume = (4 / 3) * 3.1415 * (radius ** 3)
BoW = 62.4
Fb = (Volume * BoW)

if Fb >= weight:
    print ("This sphere will float :) ")
    print ("")

else:
    print("This sphere will sink :( ")
    print ("")

print ("")
print ("")

X=0
while (X<10):
    print ("Hello")
    X = X+1
print ("")

for x in range (10):
    print ("Hello")
