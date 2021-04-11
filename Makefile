CC := gcc
CFLAGS := -lm -g -std=c99
FONTES := $(wildcard *.c)
OBJS := $(FONTES:.c=.o)
EXEC := regalloc

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	@rm -rf *.o $(EXEC)

run:$(EXEC)
	./$(EXEC)