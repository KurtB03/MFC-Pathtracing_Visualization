#Vars
COMMIT = $(shell git rev-parse --short HEAD)
NAME = calc
VERSION = $(NAME)-$(COMMIT)
WORKSPACE = $(shell pwd)
BIN = $(WORKSPACE)/bin/$(VERSION)
HOME = $(shell echo $$HOME)
LDFLAGS = -lGL -lGLU -lglut -lglfw
FILE = $(WORKSPACE)/src/main.cpp
LIB = $(WORKSPACE)/lib/*.cpp
CUBE = $(WORKSPACE)/src/cube.cpp
CUBE-BIN = $(WORKSPACE)/bin/cube-$(COMMIT)


#Compile
build:
	-mkdir $(WORKSPACE)/bin
	g++ $(FILE) $(LIB) $(CFLAGS) $(LDFLAGS) -o $(BIN)

release: package-rpm package-src
	
package-rpm: 
	#TODO: rpm config

package-src:
	-mv $(WORKSPACE)/../Download/Taschenrechner/src/*.zip $(WORKSPACE)/../Download/Taschenrechner/src/old/
	zip $(WORKSPACE)/../Download/Taschenrechner/src/$(VERSION).zip src/* 

#Test
run: build
	@echo ""
	@$(BIN)
	@#TODO: path

cube:
	-mkdir $(WORKSPACE)/bin
	g++ $(CUBE) $(LIB) $(CFLAGS) $(LDFLAGS) -o $(CUBE-BIN)
	@echo ""
	@$(CUBE-BIN)

#Clean
clean:
	-rm -Rrf $(WORKSPACE)/bin
