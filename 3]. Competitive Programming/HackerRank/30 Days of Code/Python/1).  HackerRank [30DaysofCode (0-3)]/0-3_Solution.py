###### 1st Solution

input_string = input()

print("Hello, World."+'\n'+ input_string)



###### 2nd Solution

i = 4
d = 4.0
s = 'HackerRank '

a = int(input())
b = float(input())
c = input()

print(i+a)
print(d+b)
print(s+c)


##### 3rd Solution

print(round(float(input())*(1+int(input())*.01+int(input())*.01)))

##### 4th Solution

N = int(input())

if N%2==1 or (N>3 and N<21):
    print("Weird")
else:
    print("Not Weird")