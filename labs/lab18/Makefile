.PHONY: clean all

all: compiler vm

compiler: ast.o compiler.o parser.o
	cc $^ -o $@

%.out: %.c
	cc $< -o $@

clean:
	rm *.o *.out compiler vm

