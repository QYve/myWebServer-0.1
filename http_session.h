/*
* file: http_session.h
*/
#ifndef HTTP_SESSION_H
#define HTTP_SESSION_H

#include <netinet/in.h>


#define RECV_BUFFER_SIZE    1024        /* 1KB of receive buffer */
#define    SEND_BUFFER_SIZE    1050000        /* 1.xMB of send buffer */
#define    URI_SIZE            128            /* length of uri request from client browse */

#define TIME_OUT_SEC        10            /* select timeout of secend */
#define TIME_OUT_USEC        0            /* select timeout of usecend */

#define    FILE_OK                200
#define    FILE_FORBIDEN        403            /* there are no access permission*/
#define FILE_NOT_FOUND        404            /* file not found on server */
#define    UNALLOW_METHOD        405            /* un allow http request method*/
#define FILE_TOO_LARGE        413            /* file is too large */
#define    URI_TOO_LONG        414            /* */
#define    UNSUPPORT_MIME_TYPE    415
#define    UNSUPPORT_HTTP_VERSION    505
#define    FILE_MAX_SIZE        1048576        /* 1MB the max siee of file read from hard disk */


#define ALLOW                "Allow:GET"    /* the server allow GET request method*/
#define    SERVER                "Server:Mutu(0.1 Alpha)/Linux"


/* if the connect protocol is http then this function deal with it */
int http_session(int *connect_fd, struct sockaddr_in *client_addr);

/* if http protocol return 1, else return 0 */
int is_http_protocol(char *msg_from_client);

/* get the request header's uri */
char *get_uri(char *req_header, char *uri_buf);


/* get the uri status,access return 0, not exist return 1, permission deny return 2, error return -1 */
int get_uri_status(char *uri);


/* get the mime type of the file request in uri from client's browse */
char *get_mime_type(char *uri);

/* read the file which requested by client in uri ,and store in entity_buf.
   success return bytes readed,error return -1 
*/
int get_file_disk(char *uri, unsigned char *entity_buf);

/* set http replay header's status:
    200:ok
    404:file not found

*/
int set_rep_status();

int set_error_information(unsigned char *send_buf, int errorno);


int reply_normal_information(unsigned char *send_buf, unsigned char *file_buf, int file_size, char *mime_type);

#endif
