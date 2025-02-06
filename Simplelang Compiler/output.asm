x DW 0
y DW 0
z DW 0
MOV x, 10
MOV y, 20
MOV z, x
ADD z, y
CMP z, 30
JNZ END_IF
MOV z, z
ADD z, 1
END_IF:
