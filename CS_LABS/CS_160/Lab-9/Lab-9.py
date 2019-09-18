import sys
def SortMyList(list1):


        SortedList = []
        for word in list1:
                SortedList.append(list1)
        return SortedList

def main():

        try:  #TRY CATCH ERROR HANDELING.

                txt1 = (open(str(sys.argv[1])))
                txt2 = (open(str(sys.argv[2])))
                txt3 = (open(str(sys.argv[3])))

        except:
                #does the 3 commands line arguments if user gets them wrong
                txt1 = (open('wilde.txt','r'))
                txt2 = (open('irving.txt','r'))
                txt3 = (open('bingham.txt','r'))

        finally:





                Wildetxt, Irvingtxt, Binghamtxt = txt1.read(), txt2.read(), txt3.read()

                #creates sorted word files for wilde.txt
                WildeFile = open('WildeWords','w+')
                File = SortMyList(txt1.read())
                WildeFile.write(str(File))
				print File

                #creates sorted word files for irving.txt
                IrvingFile = open('IrvingWords','w+')
                File = SortMyList(txt2.read())
                IrvingFile.write(str(File))

                #creates sorted word files for bingham.txt
                BinghamFile = open('BinghamWords','w+')
                File = SortMyList(txt3.read())
                BinghamFile.write(str(File))

main()
