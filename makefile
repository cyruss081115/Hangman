VPATH := src
OBJ = Hangman.cpp main.cpp
TARGET = play
CFLAGS = -std=c++20

$(TARGET): $(OBJ)
	@g++ $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	@rm -f $(TARGET)

	