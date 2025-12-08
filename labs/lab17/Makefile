.PHONY: clean

interp: ast.o interp.o parser.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out interp

