#include <stdlib.h>
#include <stdio.h>


 
int
main(void)
{
	//curl -X POST -d 'www' --header "Authorization: XD" localhost/cgi-bin/post

	char *method;
	int len;
	char *body;
	char *auth;
	method = getenv("REQUEST_METHOD");
	auth = getenv("HTTP_AUTHORIZATION");
	if(1){
		len = strtol(getenv("CONTENT_LENGTH"), NULL, 10);
		body = malloc(len+1);
		fgets(body, len+1, stdin);
	}

	puts("Status: 200 OK\r");
	puts("Content-Type: text/html\r");
	puts("\r");



return 1;
	char nigger[111] = "";
	sprintf(nigger, "%sauth/file", auth );


	char klopper[2*len];
	sprintf(klopper, "<html><head></head><body><video src='data:video/webm;%s'></video></body></html>",body);
		
	char dest[300] = "";
	sprintf(dest, "/stream/%s",auth);
	if(auth)
	{
		FILE *fp;
		fp = fopen(dest, "w");
		fwrite(klopper, 1, len, fp);
		fclose(fp);
		
	}

	return(EXIT_SUCCESS);
}
