.PHONY: clean

word_freq: word_freq.o hash_table.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out word_freq

