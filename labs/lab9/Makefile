.PHONY: clean

ht_test: ht_test.o hash_table.o
	cc $^ -o $@

ht_test2: ht_test2.o hash_table.o
	cc $^ -o $@

dyn_array: dyn_array.c
	cc dyn_array.c -o dyn_array

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out ht_test ht_test2 dyn_array

