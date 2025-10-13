.PHONY: clean

password_cracker: password_cracker.o sha256.o hash_table.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out password_cracker

