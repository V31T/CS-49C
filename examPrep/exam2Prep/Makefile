.PHONY: clean

myhead: myhead.c
	cc $^ -o $@

testall: test1 test2 test3
	$(info *****Testing complete)

test1: myhead
	$(info *****Testing basic case (worth 70 points))
	./myhead shakespeare-caesar.txt
	./myhead short-file.txt

test2: myhead
	$(info *****Testing intermediate case (worth 20 points))
	./myhead shakespeare-caesar.txt shakespeare-hamlet.txt shakespeare-macbeth.txt
	./myhead -n 20 shakespeare-caesar.txt

test3: myhead
	$(info *****Testing advanced case (worth 10 points))
	./myhead -n 1 shakespeare-caesar.txt shakespeare-hamlet.txt shakespeare-macbeth.txt

clean:
	rm myhead

