#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
    pthread_t p_thread[2];
    int status;
 
    pthread_mutex_init(&mutex_lock, NULL);

    pthread_create(&p_thread[0], NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread[1], NULL, t_function, (void *)"Thread2");

    pthread_join(p_thread[0], (void *)&status);
    pthread_join(p_thread[1], (void *)&status);
 
    return 0;
}
