# Makefile for tpmp-lab2-task4
# Author: Kudinova Elizaveta, group 12

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
TARGET = bin/task4_program
OBJDIR = obj
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Create target directory and build
$(TARGET): $(OBJECTS) | bin
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile .c files to .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create bin directory
bin:
	mkdir -p bin

# Create obj directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Create data directory for files
data:
	mkdir -p data

# Clean build files
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rmdir $(OBJDIR) 2>/dev/null || true

# Clean everything including data files
distclean: clean
	rm -f data/*.txt
	rmdir data 2>/dev/null || true

# Run the program
run: $(TARGET) | data
	./$(TARGET)

# Check target for GitHub Actions (non-interactive mode)
check: $(TARGET)
	@echo "Program built successfully"
	@ls -la bin/

# Test target - creates initial file and shows low performers
test: $(TARGET) | data
	@echo "Running test sequence..."
	@./$(TARGET) < test_input.txt || true

# Create a simple test input file
test_input:
	@echo "1" > test_input.txt   # Create initial file
	@echo "2" >> test_input.txt  # Load from file
	@echo "5" >> test_input.txt  # Find low performers
	@echo "0" >> test_input.txt  # Exit

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build the program (default)"
	@echo "  clean      - Remove object files and executable"
	@echo "  distclean  - Remove all generated files (including data)"
	@echo "  run        - Build and run the program"
	@echo "  check      - Verify build (for GitHub Actions)"
	@echo "  test       - Run automated test sequence"
	@echo "  test_input - Create test input file"
	@echo "  help       - Show this help"

.PHONY: all clean distclean run check test test_input help data
