cdef extern from "test.h":
        int add(int a,int b)
        int multipy(int a,int b)

print add(2,3)