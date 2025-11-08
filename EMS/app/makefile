# Simple Makefile that compiles and runs immediately

# Compiler
CC = gcc

# Source files
SRCS = main.c employee.c extras.c login.c

# Executable name
TARGET = EMSApp

# Default target: build and run
all:
	$(CC) $(SRCS) -o $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
