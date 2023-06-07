#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 4780
#define CLIENT_IP "127.0.0.3"
#define CLIENT_PORT 4782

int main()
{
	
	struct sockaddr_in server, client; 
	int sd;
	char msg[512],buff[512];
	bzero((char*)&server,sizeof(server)); 
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(SERVER_IP);
	server.sin_port=htons(SERVER_PORT);
	
	bzero((char*)&client,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=inet_addr(CLIENT_IP);
	client.sin_port=htons(CLIENT_PORT);

	sd=socket(AF_INET,SOCK_STREAM,0);
	bind(sd,(struct sockaddr*)&client,sizeof(client)); 
	connect(sd,(struct sockaddr*)&server,sizeof(server));
	do{
		printf("\nEnter a message to send to server:");
		scanf("%s",msg);
		send(sd,msg,strlen(msg)+1,0);
		memset(buff,0x0,512);
		recv(sd,buff,512,0);
		printf("Echoed msg fromm server is :%s\n",buff);
	}while(strcmp(msg,"stop"));
	close(sd);
}
