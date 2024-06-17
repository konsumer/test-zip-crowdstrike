test: main.c
	clang -o $@  -Izip/src $^ ./zip/src/zip.c

test.zip: main.c Makefile
	zip -r test.zip $^ 
