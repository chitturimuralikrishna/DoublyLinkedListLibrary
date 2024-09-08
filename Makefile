CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -Wformat -Wconversion -Wuninitialized \
         -O0 -march=native -g3 -fsanitize=address -fsanitize=undefined -fsanitize=leak \
         -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wstrict-aliasing=2 -Wnull-dereference \
         -Wformat-security -fanalyzer -Wcast-align -Wduplicated-cond -Wlogical-op \
         -Wswitch-enum -Wstrict-overflow=2 -Wdouble-promotion -Walloca -fno-omit-frame-pointer \
         -std=c2x -g -ggdb
LDFLAGS = -shared
LIB_NAME = libdll.so
TARGET = dll_test

all: $(TARGET)

dll.o: dll.c
	$(CC) -c $(CFLAGS) dll.c -o dll.o

$(LIB_NAME): dll.o
	$(CC) $(LDFLAGS) -o $(LIB_NAME) dll.o

$(TARGET): dll_test.c $(LIB_NAME)
	$(CC) $(CFLAGS) dll_test.c -L. -ldll -Wl,-rpath=. -o $(TARGET)

clean:
	rm -f dll.o $(LIB_NAME) $(TARGET)
