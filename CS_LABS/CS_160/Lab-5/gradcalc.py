def WeightGrade():
	G1 = int(input('enter your grade'))
	Weight = int(input('enter the weighting for your grade'))
	Weight = (Weight * 0.01)
	G1 = (G1 * Weight)
	return G1

def main():
	Gs = int(input('how many numbers of grades do you have'))
	G1 = 0
	G2 = 0
	x = 0
	for x in range (Gs):
		G1 = WeightGrade()
		G2 = G2 + G1
		x = (x + 1)
	print (G2)

main()
