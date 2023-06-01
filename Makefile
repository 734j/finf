CC = gcc
CFLAGS = -Wall -Werror -g
SRCS = finf.c functions.c
EXEC = finf

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -f $(EXEC)
