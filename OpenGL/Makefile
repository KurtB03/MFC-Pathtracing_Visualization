#Vars
COMMIT = $(shell git rev-parse --short HEAD)
NAME = Cube
VERSION = $(NAME)-$(COMMIT) 
WORKSPACE = $(shell pwd)
BIN = $(WORKSPACE)/bin/$(VERSION)
LDFLAGS = -lGL -lGLU -lglut
MINGWFLAGS = -lglfw -lglu32 -lopengl32 -lm -s -mwindows
FILE = $(WORKSPACE)/src/cube.cpp
#LIB = $(WORKSPACE)/src/lib/$(wildcard *.hpp)


#Compile
build:
	#TODO: build
	-mkdir $(WORKSPACE)/bin
	g++ $(FILE) -o $(BIN) $(CFLAGS) $(LDFLAGS)
	echo $(COMMIT)
	echo $(VERSION)
	#TODO: lib

#Package
install: build
	#TODO: install

release: package-exe package-deb package-rpm package-src
	
package-exe:
	x86_64-w64-mingw32-g++ $(FILE) -o $(BIN) $(MINGWFLAGS)
	#TODO: cross-compile

package-deb: 
    #TODO: deb config

package-rpm: 
	#TODO: rpm config

package-src:
	#TODO: zip

#Test
run: build
	@$(BIN)
	#TODO: path

#Clean
clean:
	-rm -rf $(WORKSPACE)/bin 
