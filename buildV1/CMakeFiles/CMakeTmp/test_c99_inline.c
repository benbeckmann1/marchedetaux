extern inline void* foo () { foo(); return &foo; }
        int main (int argc, char *argv[]) { return foo() != 0; }
        