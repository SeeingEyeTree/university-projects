

j=8
x=[3,3,3]
use=[1,2,3,4]
with open('run.py', 'w') as file:
    file.write(f'use=[{use[0]},{use[1]},{use[2]},{use[3]}]\n')
str1="s=use[0]_use[1]_use[2]_use[3]"
#print(str1)
for i in range(3):
    if x[i]==1:
        str1=str1.replace("_","+",1)
    elif x[i]==2:
        str1=str1.replace("_","-",1)
    elif x[i]==3:
        str1=str1.replace("_","*",1)
    elif x[i]==4:
        str1=str1.replace("_","/",1)
    j=j+7
with open('run.py', 'a') as file:
    file.write(str1)


import run
print(run.s)
if run.s==10:
    ans='y'
else:
    ans='n'
