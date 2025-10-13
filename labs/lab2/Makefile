SHIFT = 3

.PHONY: clean run

bruteforce: bruteforce.o caesar.o
	cc bruteforce.o caesar.o -o bruteforce

test_cipher: test_cipher.o caesar.o
	cc caesar.o test_cipher.o -o test_cipher

caesar.o: caesar.c caesar.h
	cc -c caesar.c -o caesar.o

test_cipher.o: test_cipher.c
	cc -c test_cipher.c -o test_cipher.o

clean:
	rm *.o test_cipher

run: test_cipher
	./test_cipher ${SHIFT}
