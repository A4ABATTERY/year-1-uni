y = input ('How many bytes would you like')
z = int(y)*8
print ('Max unsigned: '+ str(2**(z)-1))
print ('Max signed: '+ str (2**(z-1)-1))
print ('Min Unsigned: '+ str (-2**(z-1)))
print ('Min signed: ' + str (-2**(z-1)-1))
