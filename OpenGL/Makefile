#Vars
COMMIT = $(shell git rev-parse --short HEAD)
NAME = cube
VERSION = $(NAME)-$(COMMIT)
WORKSPACE = $(shell pwd)
BIN = $(WORKSPACE)/bin/$(VERSION)
HOME = $(shell echo $$HOME)
LDFLAGS = -lGL -lGLU -lglut -I$(LIB)
FILE = $(WORKSPACE)/src/cube.cpp
LIB = $(WORKSPACE)/src/lib


#Compile
build:
	#TODO: build
	-mkdir $(WORKSPACE)/bin
	g++ $(FILE) $(CFLAGS) $(LDFLAGS) -o $(BIN)
	#TODO: lib

release: package-rpm package-src
	
package-rpm: 
	#TODO: rpm config

package-src:
	-mv $(WORKSPACE)/../Download/Taschenrechner/src/*.zip $(WORKSPACE)/../Download/Taschenrechner/src/old/
	zip $(WORKSPACE)/../Download/Taschenrechner/src/$(VERSION).zip src/* 

#Test
run: build
	@$(BIN)
	#TODO: path

#Clean
clean:
	-rm -Rrf $(WORKSPACE)/bin
