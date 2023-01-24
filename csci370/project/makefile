G = g++-4.9
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei

proj: main.cpp
	$(G) $(CFLAGS) $(LFLAGS) main.cpp -o proj

clean:
	rm -f main
