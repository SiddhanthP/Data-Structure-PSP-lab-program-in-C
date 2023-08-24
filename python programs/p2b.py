def BtoD(binary):
    decimal,i=0,0
    while (binary!=0):
        dec=binary%10
        decimal=decimal+dec*pow(2,i)
        binary=binary//10
        i+=1
        print(decimal)
        return decimal
    
def OtoD(octal):
    decimal2,i=0,0
    while(octal!=0):
        oct=octal%10
        decimal2=decimal2+oct*pow(8,i)
        octal=octal//10
        i+=1
        print('Octal number in Decimal form',decimal2)
        return decimal2

def DtoH(n):
    HexaDecinum=''
    while n!=0:
        temp=0
        temp=n%16
        if temp<10:
            HexaDecinum=str(temp)+HexaDecinum
        else :
            HexaDecinum=ch(temp+87)+HexaDecinum
        n=n//16
        return HexaDecinum

bin=int(input("enter the binary number\n"))
bdecimal=BtoD(bin)
print("decial number is",bdecimal)

octal=int(input("enter the octal number"))
odecimal=DtoH(octal)
print("decimal number is",odecimal)

hex=DtoH(odecimal)
print("Hexa-decimal number for given octal number is",hex)
