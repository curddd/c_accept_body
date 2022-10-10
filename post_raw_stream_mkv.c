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
	//freopen(NULL, "rb", stdin);
	fread(body, len, 1, stdin);

	puts("Status: 200 OK\r");
	puts("Content-Type: text/html\r");
	puts("\r");

	
	puts(getenv("CONTENT_LENGTH"));
	printf("xx  %d xx  ", len); 

	char *klopper;
	klopper = malloc(len*2);
	sprintf(klopper, "<html><head></head><body><video controls><source type=\"video/mp4\" src='%s.mkv'></video></body></html>", auth);

	char dest[300] = "";
	char vid_dest[300] = "";
	sprintf(dest, "/kaiserreich.online/stream/%s.html",auth);
	sprintf(vid_dest, "/kaiserreich.online/stream/%s.mkv",auth);
	if(auth)
	{
		FILE *fp;
		fp = fopen(dest, "w");
		fprintf(fp, "%s", klopper);
		fclose(fp);


		fp = fopen(vid_dest, "ab");
		fwrite(body, len, 1, fp);
		fclose(fp);

		
	}

	return(EXIT_SUCCESS);
}
