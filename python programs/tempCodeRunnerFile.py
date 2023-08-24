sentence=input("enter the sentence\n")
word_list=sentence.split("")
print("the sentence has",len(word_list),"words")
Dcnt=Upcnt=Lcnt=0
for ch in sentence:
    if '0'<=ch<='9':
        Dcnt+=1
    elif 'a'<=ch<='z':
        Lcnt+=1
    elif 'A'<=ch<='Z':
        Upcnt+=1
print("this sentence has",Dcnt,"digits",Upcnt,"digits",Lcnt,"digits")