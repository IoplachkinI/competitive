
def main():
    while True:
        try:
            a = [int(x) for x in input().split()]
        except EOFError:
            break
        
        if (len(a) > 0):
            a.pop()
            
        for i in range(1, len(a)):
            if (a[i - 1] == 0):
                continue
            a[i] *= a[i-1]

        maxmult = max(a)
        for i in range(0, len(a)):
            for j in range(i - 1, -1, -1):
                if (a[j] == 0):
                    break
                cur = a[i] // a[j]
                maxmult = max(cur, maxmult)
        print(maxmult)

main()