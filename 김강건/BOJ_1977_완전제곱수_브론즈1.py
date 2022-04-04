import math

start = math.ceil(math.sqrt(int(input())))
end = math.floor(math.sqrt(int(input())))

if end - start < 1:
    print(-1)
    exit()

sum = 0

for num in range(start, end + 1):
    sum += math.pow(num, 2)

print(int(sum))
print(int(math.pow(start, 2)))
