def Assignment6_2():

    def filter_list(Nums):
        Nums = [element for element in Nums if element.isdigit()]
        #print (Nums)
        return Nums
    def Convert_String(Nums):
        Nums = [int(x) for x in Nums]
        return Nums


    def Compare_LEN(Nums1, Nums2):
        if len(Nums2) == len(Nums1):
            print ('\nBoth lists are the same length\nSame length: Yes')
        else:
            print ('\nThe lists are different length\nSame length: No')


    def Compare_VAL(Nums1, Nums2):
        Sum_Nums1 = 0
        Sum_Nums2 = 0
        for x in Nums1:
            Sum_Nums1 += x 
        for x in Nums2:
            Sum_Nums2 += x
        if Sum_Nums2 == Sum_Nums1:
            print ('\nThe sums are equal', end='')
            print ('Sum is equal to: ', Sum_Nums2)
        else:
            print ('\nthe sums are not eqaul. ', 'List 1: ', Sum_Nums1, ', ', 'List 2: ', Sum_Nums2)

    def Commonality(Nums1, Nums2):
        Common_Nums = []
        for x in Nums1:
            if x in Nums2:
                Common_Nums.append(x)
        return Common_Nums

    string1 = [(x) for x in str(input('\nEnter some numbers for your first list\n')).split()]
    string2 = [(x) for x in str(input('\nEnter some numbers for your second list\n')).split()]
    
    string1 = filter_list(Nums = string1)
    string2 = filter_list(Nums = string2)
    
    Nums1 = Convert_String(Nums = string1)
    Nums2 = Convert_String(Nums = string2)
    #print (string1)
    #print (Nums1)
    #print (string2)
    #print (Nums2)
    Compare_LEN(Nums1, Nums2)
    Compare_VAL(Nums1, Nums2)
    numbers = Commonality(Nums1, Nums2)
    x = 0 
    print ('common numbers include: ', end='')
    for x in (numbers):
        print (x, ' ', end='')

    print ('\n\nProgram End\n\n')

Assignment6_2()
