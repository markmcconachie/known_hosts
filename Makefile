PREFIX?=/usr/local
CFLAGS=-Wall -g

all: known_hosts

known_hosts: known_hosts_file.o display.o utils.o commands.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install known_hosts $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -rf known_hosts *.o