from copy import deepcopy


def is_acceptable(arg: int):
    if arg < 0:
        raise ValueError
    elif arg == 0:
        return True
    
    while arg != 1:
        if arg % 2 != 0:
            return False
        else:
            arg /= 2
        
    return True

class Board:
    def __init__(self):
        self.size = int(input())
        
        if self.size < 1 or 21 <= self.size:
            raise ValueError
        
        self.data = []
        
        for i in range(self.size):
            tmp = list(map(int, input().split(" ")))
            
            if len(tmp) != self.size:
                raise ValueError
            elif tmp != list(filter(is_acceptable, tmp)):
                raise ValueError
            
            self.data.append(tmp)
            
        self.initial_data = deepcopy(self.data)
            
    def move_upward(self):
        for j in range(self.size):
            tmp = [e[j] for e in self.data if e[j] != 0]
            
            for i in range(len(tmp)):
                if i == 0:
                    continue
                
                if tmp[i] == tmp[i-1]:
                    tmp[i-1] *= 2
                    tmp[i] = 0
                    
            tmp = [e for e in tmp if e != 0]
            
            while len(tmp) != self.size:
                tmp = tmp + [0]
                
            for i in range(self.size):
                self.data[i][j] = tmp[i]
                
        return self
    
    def move_downward(self):
        for j in range(self.size):
            tmp = [e[j] for e in self.data if e[j] != 0]
            
            for i in range(len(tmp))[::-1]:
                if i == len(tmp) - 1:
                    continue
                
                if tmp[i] == tmp[i+1]:
                    tmp[i+1] *= 2
                    tmp[i] = 0
                    
            tmp = [e for e in tmp if e != 0]
            
            while len(tmp) != self.size:
                tmp = [0] + tmp
                
            for i in range(self.size):
                self.data[i][j] = tmp[i]
                
        return self
    
    def move_left(self):
        for i in range(self.size):
            tmp = [e for e in self.data[i] if e != 0]
            
            for j in range(len(tmp)):
                if j == 0:
                    continue
                
                if tmp[j] == tmp[j-1]:
                    tmp[j-1] *= 2
                    tmp[j] = 0
                    
            tmp = [e for e in tmp if e != 0]
            
            while len(tmp) != self.size:
                tmp = tmp + [0]
                
            for j in range(self.size):
                self.data[i][j] = tmp[j]
                
        return self
    
    def move_right(self):
        for i in range(self.size):
            tmp = [e for e in self.data[i] if e != 0]
            
            for j in range(len(tmp))[::-1]:
                if j == len(tmp) - 1:
                    continue
                
                if tmp[j] == tmp[j+1]:
                    tmp[j+1] *= 2
                    tmp[j] = 0
                    
            tmp = [e for e in tmp if e != 0]
            
            while len(tmp) != self.size:
                tmp = [0] + tmp
                
            self.data[i] = tmp
    
        return self
    
    def get_largest(self):
        tmp = []
        for i in range(self.size):
            tmp.append(max([e for e in self.data[i]]))
            
        return max(tmp)
    
board = Board()
move = [board.move_right, board.move_upward, board.move_left, board.move_downward]
scores = []

for i in move:
    for j in move:
        for k in move:
            for m in move:
                for n in move:
                    i()
                    j()
                    k()
                    m()
                    n()
                    scores.append(board.get_largest())
                    board.data = deepcopy(board.initial_data)
                    
print(max(scores))
