CC :=g++
LDFLAGS := -Wall
NAMESC :=$(wildcard *.cpp)
NAMES :=$(NAMESC:.cpp=)

all: $(NAMES)

%:%.c
		$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
		rm -rf $(NAMES)