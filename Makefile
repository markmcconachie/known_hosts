CFLAGS=-Wall -g

all: known_hosts

known_hosts: known_hosts_file.o display.o utils.o commands.o

clean:
	rm -rf known_hosts