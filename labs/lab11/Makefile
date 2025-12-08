.PHONY: clean

test_merkle_tree: test_merkle_tree.o merkle_tree.o sha256.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out test_merkle_tree

