MOV DX string
MOV AX 0900H
INT 21H
MOV AX 4C00H
INT 21H
string: DB 46
test: DB 24