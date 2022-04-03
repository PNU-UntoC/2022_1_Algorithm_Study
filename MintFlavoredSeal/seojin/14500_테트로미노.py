height, width = tuple(map(int, input().split(" ")))
table = []

for i in range(height):
    table.append(tuple(map(int, input().split(" "))))

tmp = []
    
# I block
    
for i in range(height-3):
    for j in range(width):
        tmp.append(table[i][j] + table[i+1][j] + table[i+2][j] + table[i+3][j])
            
for i in range(height):
    for j in range(width-3):
        tmp.append(table[i][j] + table[i][j+1] + table[i][j+2] + table[i][j+3])
            
# L block
    
for i in range(height-2):
    for j in range(width-1):
        tmp.append(table[i][j] + table[i+1][j] + table[i+2][j] + table[i][j+1])
        tmp.append(table[i][j] + table[i+1][j] + table[i+2][j] + table[i+2][j+1])
        tmp.append(table[i][j+1] + table[i+1][j+1] + table[i+2][j+1] + table[i][j])
        tmp.append(table[i][j+1] + table[i+1][j+1] + table[i+2][j+1] + table[i+2][j])
            
for i in range(height-1):
   for j in range(width-2):
        tmp.append(table[i][j] + table[i+1][j] + table[i][j+1] + table[i][j+2])
        tmp.append(table[i][j] + table[i+1][j] + table[i+1][j+1] + table[i+1][j+2])
        tmp.append(table[i][j] + table[i][j+1] + table[i][j+2] + table[i+1][j+2])
        tmp.append(table[i+1][j] + table[i+1][j+1] + table[i][j+2] + table[i+1][j+2])
            
# O block
    
for i in range(height-1):
    for j in range(width-1):
        tmp.append(table[i][j] + table[i+1][j] + table[i][j+1] + table[i+1][j+1])
            
# Z block
    
for i in range(height-2):
    for j in range(width-1):
        tmp.append(table[i][j] + table[i+1][j] + table[i+1][j+1] + table[i+2][j+1])
        tmp.append(table[i][j+1] + table[i+1][j] + table[i+1][j+1] + table[i+2][j])
            
for i in range(height-1):
    for j in range(width-2):
        tmp.append(table[i][j] + table[i][j+1] + table[i+1][j+1] + table[i+1][j+2])
        tmp.append(table[i+1][j] + table[i][j+1] + table[i+1][j+1] + table[i][j+2])
            
# T block
    
for i in range(height-2):
    for j in range(width-1):
        tmp.append(table[i+1][j] + table[i+1][j+1] + table[i][j] + table[i+2][j])
        tmp.append(table[i+1][j] + table[i+1][j+1] + table[i][j+1] + table[i+2][j+1])
            
for i in range(height-1):
    for j in range(width-2):
        tmp.append(table[i][j+1] + table[i+1][j+1] + table[i][j] + table[i][j+2])
        tmp.append(table[i][j+1] + table[i+1][j+1] + table[i+1][j] + table[i+1][j+2])

print(max(tmp))
