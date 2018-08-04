CC_FILES = $(wildcard */*.cpp)
BIN_FILES = $(notdir $(CC_FILES:.cpp=))
CC_FLAGS = -std=c++0x -Wall -O2 -lm -Wl,-stack_size -Wl,0x1000000
CC = g++

.SECONDEXPANSION:
$(BIN_FILES): %: $$(wildcard */$$**.cpp)
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
