webserver:get_time.o http_session.o init_socket.o webserver.o
	gcc -std=c99 -o webserver get_time.o http_session.o init_socket.o webserver.o

get_time.o:get_time.c get_time.h
	gcc -std=c99 -o get_time.o -c get_time.c

http_session.o:http_session.c http_session.h get_time.h
	gcc -std=c99 -o http_session.o -c http_session.c

init_socket.o:init_socket.c init_socket.h
	gcc -std=c99 -o init_socket.o -c init_socket.c

webserver.o:webserver.c init_socket.h get_time.h http_session.h
	gcc -std=c99 -o webserver.o -c webserver.c

clean:
	rm -f *.o webserver
