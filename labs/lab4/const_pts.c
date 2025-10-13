int main() {
    char s[] = "hello";

    const char * p1 = s;
    char const * p2 = s;
    char * const p3 = s;

    p1++; // OK
    p2++; // OK
    //p3++; // error

    //p1[0] = 'X'; // error
    //p2[0] = 'X'; // error
    p3[0] = 'X'; // OK

    const char * const p4 = s;
    //p4++; // error
    //p4[0] = 'X'; // error
}