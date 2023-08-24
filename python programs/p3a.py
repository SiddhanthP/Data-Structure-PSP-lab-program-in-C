sentence=input("enter the sentence\n")
word_list=sentence.split()
print("the sentence has",len(word_list),"word")
Dcnt=Upcnt=Lcnt=0
for ch in sentence:
    if '0'<=ch<='9':
        Dcnt+=1
    elif 'a'<=ch<='z':
        Lcnt+=1
    elif 'A'<=ch<='Z':
        Upcnt+=1
print("this sentence",word_list,"has",Dcnt,"Numbers ",Upcnt,"Uppercase Alphabets and",Lcnt,"Lowercase Alphabets")