PLATFORM := $(shell uname)

COMPILER := g++
COMPILER_FLAGS := -Wreorder -c -std=c++14 `sdl2-config --cflags` `freetype-config --cflags`

SRCDIR  := src
SRCEXT  := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

OBJDIR  := bin
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

MAC_LIBRARIES := -framework OpenGl -framework CoreFoundation -I/usr/local/include -lglew -lSOIL `sdl2-config --libs` -ljsoncpp -llua5.1 -ldl
LINUX_LIBRARIES := -lGL -lGLEW -I /usr/lib/x86_64-linux-gnu/ -I /usr/local/include -lSOIL -lpthread `sdl2-config --libs` -ljsoncpp

NAME := opengl_playground

# Try to auto detect the platform to build for
ifeq ($(PLATFORM),Darwin)
	LIBRARIES := $(MAC_LIBRARIES)
	TIMEOUT_SCRIPT := gtimeout
else ifeq ($(PLATFORM),Linux)
	LIBRARIES := $(LINUX_LIBRARIES)
	TIMEOUT_SCRIPT := timeout
endif

$(NAME): obj/main.o $(SOURCES) $(OBJECTS)
	$(COMPILER) -std=c++11 -I$(SRCDIR) -I/usr/local/include/lua-5.1/ $(OBJECTS) $(LIBRARIES) -o opengl_playground

$(SOURCES): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(shell find $(SRCDIR) -type d | sed "s/$(SRCDIR)/$(OBJDIR)/")

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(COMPILER) $(COMPILER_FLAGS) -I$(SRCDIR) -I/usr/local/include/lua-5.1/ $< -c -o $@

run: $(NAME)
	./$(NAME)

discard:
	@ git clean -df
	@ git checkout -- .

clean:
	rm -rf $(OBJDIR)/

configure-linux:
	@ sudo apt-get install libglew-dev libglm-dev libsdl2-dev
	@ wget http://www.lonesock.net/files/soil.zip
	@ unzip soil.zip -d soil
	@ rm soil.zip
	@ rm soil/Simple\ OpenGL\ Image\ Library/lib/libSOIL.a
	@ mkdir soil/Simple\ OpenGL\ Image\ Library/projects/makefile/obj
	@ cd soil/Simple\ OpenGL\ Image\ Library/projects/makefile && make && sudo make install
	@ rm -r soil
