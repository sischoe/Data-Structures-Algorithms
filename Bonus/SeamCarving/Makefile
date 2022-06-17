

all: build
	

build: *.cpp *.h
	clang++ *.cpp -o seamcarve -O2

run: build
	./seamcarve

clean: 
	rm seamcarve
	rm -rf out

