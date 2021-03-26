#Vars
COMMIT = $(shell git rev-parse --short HEAD)
NAME = cube
VERSION = $(NAME)-$(COMMIT)
WORKSPACE = $(shell pwd)
BIN = $(WORKSPACE)/bin/$(VERSION)
HOME = $(shell echo $$HOME)
LDFLAGS = -lGL -lGLU -lglut -I$(LIB)
MINGWFLAGS = -lglu32 -lglfw
FILE = $(WORKSPACE)/src/cube.cpp
LIB = $(WORKSPACE)/src/lib


#Compile
build:
	#TODO: build
	-mkdir $(WORKSPACE)/bin
	g++ $(FILE) $(CFLAGS) $(LDFLAGS) -o $(BIN)
	#TODO: lib

#Package
install: build
	chmod +x bin/$(VERSION)
	mkdir -p $(HOME)/bin/$(NAME)
	cp bin/$(VERSION) $(HOME)/bin/$(NAME)/$(COMMIT)
	sudo ln -s $(HOME)/bin/$(NAME)/$(COMMIT) /usr/local/bin/$(NAME)
	#TODO: install

release: package-deb package-rpm package-src
	
package-exe:
	-mkdir $(WORKSPACE)/bin
	export GNU_HOST=x86_64-w64-mingw32
	x86_64-w64-mingw32-g++ $(FILE) $(MINGWFLAGS) -I$(LIB)/glfw -o $(BIN).exe
	#TODO: opengl
	-mv $(WORKSPACE)/../Download/Taschenrechner/win/*.exe $(WORKSPACE)/../Download/Taschenrechner/win/old/
	-mv $(BIN)/$(VERSION).exe $(WORKSPACE)/../Download/Taschenrechner/win/$(VERSION).exe

package-deb: 
    #TODO: deb config

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

uninstall:
	-rm -rf $(HOME)/bin/$(NAME)
