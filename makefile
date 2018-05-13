.PHONY:clean
main : binarytree.c
	gcc -o $@ $^
clean:
	rm main
