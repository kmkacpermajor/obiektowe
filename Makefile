CC :=g++
LDFLAGS := -Wall
NAMESC :=$(wildcard **/main.cpp)
NAMESC := $(wildcard **/**/main.cpp $(NAMESC))
NAMES :=$(NAMESC:.cpp=)

all: $(NAMES)

%:%.c
		$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
		rm -rf $(NAMES)