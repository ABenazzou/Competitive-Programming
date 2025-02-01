m = int(input())


for i in range(m):
    n = int(input())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))


    result = a[n-1]

    for j in range(n-2, -1, -1):
        if(a[j] > b[j+1]):
            result += a[j] - b[j+1]
    
    print(result)