import sys

def main():
    test_case_t = int(input())
    for _ in range(test_case_t):
        x, y, z, w = map(int, input().split())
        if x > y:
            x, y = y, x
        if z > w:
            z, w = w, z
        if z >= x:
            x, y, z, w = z, w, x, y
        if x >= z and x <= w and y >= w:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()