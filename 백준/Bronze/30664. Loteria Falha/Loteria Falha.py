 #"PREMIADO"를 출력하세요. 그렇지 않으면 "TENTE NOVAMENTE"
while 1:
    a=int(input())
    if a==0:
        break
    if a%42==0:
        print('PREMIADO')
    else:
        print('TENTE NOVAMENTE')