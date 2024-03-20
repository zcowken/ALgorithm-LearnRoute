
def main():
    #code here
    n = int(input())
    m = ""
    dd = {}
    mi = 1000000

    for i in range(n):
        s1 = input().strip().split()
        s = s1[0]
        v = int(s1[1])
        if not dd.get(s):
            dd[s] = 1000
        dd[s]+=v
        if mi>dd[s]:
            mi = dd[s]
            m = s

    # for i in dd.keys():
    #     if(mi>dd[i]):
    #         m = i
    print(m)
    print(dd[m])
    
    pass


if __name__ == '__main__':
    main();

# 3
# meigui 110
# yueji -20
# yueji 100