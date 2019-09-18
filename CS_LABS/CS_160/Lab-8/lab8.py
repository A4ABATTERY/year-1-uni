def count_elements(a):
	LTR = input('Enter a letter that you would like to count: ')
	LTR = list(LTR)
	AsciiLTR = ord(LTR[0])
	if (90 <= AsciiLTR) and (AsciiLTR >= 65):
		AsciiLTR = AsciiLTR - 32
		Count = len([x for x in a if x == AsciiLTR])
	else:
		print ('wrong input')
		Count = 0
	print (LTR[0], '-', Count)

def ASCIIBANK(lst):
	lst = list(lst)
	lst = [x for x in lst if x.isalpha()]
	Asciibank = [ord(x) for x in lst]
	return Asciibank
	
def main():
	alice = open('alice.txt', 'r')
	alicestr =  (alice.read())
	candide = open('candide.txt', 'r')
	candidestr = (candide.read())
	ulysses = open('ulysses.txt', 'r')
	ulyssesstr = (ulysses.read())
	print ('1 = Alice in Wonderland')
	print ('2 = Candide')
	print ('3 = Ulysses')
	re = 1
	while re == 1:
		Book = int(input('which book would you like to read: ' ))
		if Book == 1:
			ASCIIBank = ASCIIBANK(alicestr)
			re = 0
		elif Book == 2:
			ASCIIBank = ASCIIBANK(candidestr)
			re = 0
		elif Book == 3:
			ASCIIBank = ASCIIBANK(ulyssesstr)
			re = 0
		else:
			print('wrong input')
			re = 1
	lstCAPS = []
	lstlcas = []
	place = 0
	for x in ASCIIBank:
		if 90 <= ASCIIBank[place]:
			lstCAPS.append(ASCIIBank[place] - 32)
		elif 90 >= ASCIIBank[place]:
			lstlcas.append(ASCIIBank[place])
		place += 1
	ASCIIBank = lstCAPS + lstlcas
	repeat = ('0')
	while 	repeat != ('1'):
		count_elements(ASCIIBank)
		repeat = str(input('Enter 1 to exit. Enter any other key to continue and count within the file you picked.'))
main()
