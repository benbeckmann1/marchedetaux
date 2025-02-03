extern int foo (int);
        extern inline int foo (int x) { return x+1;}
        int foo (int x) { return x+1;}
        int main (int arg, char *argv[]) { foo(1); return 0;}
        