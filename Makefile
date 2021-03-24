test:
	@g++ ./Pathtracer/test.cpp -o ./Pathtracer/bin/test
	@./Pathtracer/bin/test

build:
	@g++ Pathtracer/test.cpp -o Pathtracer/bin/test

install:
	
run: test


check : test