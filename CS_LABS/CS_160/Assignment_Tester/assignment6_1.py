def MakeNameList():
    NameBank = list(input('Enter in some names: '))
    return NameBank

def Assignment6_1():
    def CountElements():
        LTR = input('enter a letter that you want to count: ')
        LTR = list(LTR)
       # print (LTR)
        AsciiLTR = ord(LTR[0])
        if 90 < AsciiLTR:
            AsciiLTR = AsciiLTR - 32
        elif AsciiLTR == []:
            print ('wrong input')
        Count = len([i for i in ASCIIBank if i == AsciiLTR])
        print (LTR[0], '-', Count)
    LetterBank = MakeNameList()
    LetterBank.sort()
    LetterBank = [item for item in LetterBank if item.isalpha()]
    ASCIIBank = [ord(x) for x in LetterBank]
    #print (ASCIIBank)
    x = 0
    place = 0
    lstCaps = []
    lstLcas = []
    for x in ASCIIBank:
        if 90 < ASCIIBank[place]:
            lstCaps.append(ASCIIBank[place] - 32)
        elif 90 >= ASCIIBank[place]:
            lstLcas.append(ASCIIBank[place])
        place += 1
        x += 1
    ASCIIBank = lstLcas + lstCaps
    #print (ASCIIBank)
    repeat = ('0')
    while repeat != ('1'):
        CountElements()
        repeat = str(input('Enter 1 to exit. Enter any other key to continue:'))


Assignment6_1()
