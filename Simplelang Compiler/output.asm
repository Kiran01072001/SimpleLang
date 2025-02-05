a DB 0
b DB 0
c DB 0
MOV a, 10
MOV b, 20
MOV c, a
ADD c, b
CMP c, 30
JNZ END_IF
MOV c, c
ADD c, 1
END_IF:
