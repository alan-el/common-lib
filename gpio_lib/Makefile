CFLAGS=-Wall 

exec = gpioexport gpiounexport gpiodir gpiosetval gpiogetval

all: $(exec)
	sudo cp -u libgpioz.so /usr/lib
	mkdir -p bin
	mv $(exec) bin

$(exec): %:%.c libgpioz.so
	gcc $(CFLAGS) $< -lgpioz -L. -o $@

#gpioexport: gpioexport.c libgpioz.so gpioz.h
#	gcc $(CFLAGS) gpioexport.c -lgpioz -L. -o gpioexport
#gpiounexport: gpiounexport.c libgpioz.so gpioz.h
#	gcc $(CFLAGS) gpiounexport.c -lgpioz -L. -o gpiounexport
#gpiodir: gpiodir.c libgpioz.so gpioz.h
#	gcc $(CFLAGS) gpiodir.c -lgpioz -L. -o gpiodir

libgpioz.so: gpioz.o
	gcc $(CFLAGS) -shared -o libgpioz.so gpioz.o 

gpioz.o: gpioz.c gpioz.h
	gcc $(CFLAGS) -c gpioz.c -o gpioz.o

.PHONY: clean

clean:
	rm *.o
