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

	len = strtol(getenv("CONTENT_LENGTH"), NULL, 10);
	body = malloc(len+1);
	fgets(body, len+1, stdin);

	puts("Status: 200 OK\r");
	puts("Content-Type: text/html\r");
	puts("\r");

	
	char *klopper;
	klopper = malloc(len*2);
	sprintf(klopper, "<html><head></head><body><video controls><source type=\"video/webm\" src='data:video/webm;base64,%s'></video></body></html>",body);

	char dest[300] = "";
	sprintf(dest, "/kaiserreich.online/stream/%s.html",auth);
	if(auth)
	{
		FILE *fp;
		fp = fopen(dest, "w");
		//fwrite(klopper, 1, len, fp);
		fprintf(fp, "%s", klopper);
		fclose(fp);
		
	}

	return(EXIT_SUCCESS);
}
