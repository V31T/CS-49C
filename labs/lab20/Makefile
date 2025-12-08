.PHONY: clean

high_card: cards.o high_card.o
	cc $^ -o $@

test_shuffle: cards.o test_shuffle.o
	cc $^ -o $@

clean:
	rm *.o test_shuffle high_card

