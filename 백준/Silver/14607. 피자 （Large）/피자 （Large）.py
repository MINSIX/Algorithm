def main():
    import sys
    input = sys.stdin.read

    N = int(input().strip())
    cnt = (N) * (N - 1) // 2
    print(cnt)

if __name__ == "__main__":
    main()
