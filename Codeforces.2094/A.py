t = int(input())
for i in range(t):
    s = input().split()
    res = ""
    for x in s:
        res += x[0]
    print("".join(res))
