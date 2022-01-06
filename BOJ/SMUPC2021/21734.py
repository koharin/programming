in_str = input()
for i in in_str:
    sum = 0
    for j in str(ord(i)):		
        sum += int(j)
    for k in range(sum):
        print(i, end='')
    print()
