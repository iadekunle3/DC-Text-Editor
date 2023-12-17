# Makefile for kilo project

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Source file
SRC = Drm.c

# Target executable
TARGET = drm

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Clean up the executable
clean:
	rm -f $(TARGET)
