# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <math.h>

pthread_t id,id2;

void * nossa_thread (void *apelido) {
	float k;
	while (1) {
		printf("1\n");
		k=sin(k+123);
		sleep(2);
	}
	pthread_exit(NULL);
}

void * minha_thread_2(void *apelido) {
	while (1) {
		printf("2\n");
		sleep(4);
	}
	pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
	pthread_create (&id, NULL , (void *) minha_thread , NULL);
	pthread_create (&id2,NULL , (void *) minha_thread_2,NULL);

	while (1);
	return 0;
}
