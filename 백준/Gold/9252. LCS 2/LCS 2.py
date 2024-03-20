import sys
input = sys.stdin.readline

s = input().strip()
b = input().strip()

m = len(s)
n = len(b)
ss = [["" for _ in range(n + 1)] for _ in range(m + 1)]

for i in range(1, m + 1):
    for j in range(1, n + 1):
        if s[i - 1] == b[j - 1]:
            ss[i][j] = ss[i - 1][j - 1] + s[i - 1]
        else:
            if len(ss[i][j - 1]) < len(ss[i - 1][j]):
                ss[i][j] = ss[i - 1][j]
            else:
                ss[i][j] = ss[i][j - 1]

print(len(ss[m][n]))
print(ss[m][n])
