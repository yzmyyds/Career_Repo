# s_in=input()
# print(type(s_in))

s_in="1,2,3"
l=s_in.split(',')
print(l)
print(type(l[0]))
print(map(int,l))
for m in map(int,l):
    print(m,type(m))
print(type(map(int,l)))

int_l=list(map(int,l))
print(int_l)

n=int(input())
for _ in range(n):
    s=input()
    num_l=list(map(int,s.split(' ')))
    y=num_l[0]
    x=num_l[1]
    tar=max(x,y)
    while (y!=0 and x!=0):
        sub=min(x,y)
        y%=sub
        sub=min(x,y)
        if (sub==0): break
        x%=sub
    if (y==0): print("you")
    else: print("xiaoming")