CC :=g++
LDFLAGS := -Wall
NAMESC :=$(wildcard **/*.cpp)
NAMESC := $(wildcard **/**/*.cpp $(NAMESC))
NAMES :=$(NAMESC:.cpp=)

all: $(NAMES)

%:%.c
		$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
		rm -rf $(NAMES)