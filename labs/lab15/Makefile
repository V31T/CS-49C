.PHONY: clean

mnemonic: mnemonic.o hash_table.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out mnemonic

