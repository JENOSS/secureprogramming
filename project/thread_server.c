#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socekt.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#define BUF_SIZE 100;
#define MAX_CLNT 100;
#define MAX_IP 30;

void error_handling(char *msg);

int clnt_cnt=0;
int clnt_sock[MAX_CLNT];
pthread_mutex_t mutex_lock;



int global_data = 0 ;

void *t_function(void *data)
{
	int i;
	char * thread_name = (char*)data;	
	

	pthread_mutex_lock(&mutex_lock);

       	global_data = 0; // 쓰레드마다 0부터 시작

	for(i=0;i<3;i++){
		printf("%s COUNT %d\n", thread_name, global_data);
		global_data++;
		sleep(1);
	}		
 
	pthread_mutex_unlock(&mutex_lock);
}
 
int main()
{
  	int serv_sock, clnt_cock;
	struct sockaddr_in serv_adr,clnt_adr;
	int clng_adr_sz;

	pthread_t t_id;

	ptrhead_mutex_init(&mutex_lock, NULL);
	serv_sock=socket(PF_INET, SOCK_STREAM,0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");

	while(1)
	{
		clnt_adr_sz=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

		pthread_mutex_lock(&mutx_lock);
		clnt_socks[clnt_cnt++



       	pthread_t p_thread[2];
    
	int status;
 
    
	pthread_mutex_init(&mutex_lock, NULL);

   
       	pthread_create(&p_thread[0], NULL, t_function, (void *)"Thread1");
   
       	pthread_create(&p_thread[1], NULL, t_function, (void *)"Thread2");

   
       	pthread_join(p_thread[0], (void *)&status);
   
       	pthread_join(p_thread[1], (void *)&status);
 
 
     	return 0;
}


void error_handling(char *msg){
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}
