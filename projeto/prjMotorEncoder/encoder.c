//Bibliotecas basicas de C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bibliotecas de threads, mutex getsockname
#include <pthread.h>
#include <semaphore.h>

//Bibliotecas de funções diversas
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

//Bibliotecas de Redes
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>


/////////////////////////////////////////////////VARIÁVEIS GLOBAIS/////////////////////////////////////

pthread_t id1, id2, id3;
float posicaoFinal, ddp, erro;
float coef, correcao;

/////////////////////////////////////////////////FUNÇÕES///////////////////////////////////////////////

//FUNÇÃO DA PRIMEIRA THREAD
void * minha_thread_1 (void *apelido) {
	float k;
	while (1) {
		k = sin(k+ (3.14/2));
		printf("%f\n", k);
		sleep(2);
	}
	pthread_exit(NULL);
}

//FUNÇÃO DA SEGUNDA THREAD
void * minha_thread_2(void *apelido) {
	sleep(1);
	while (1) {
		printf(" 2\n");
		sleep(2);
	}
	pthread_exit(NULL);
}

//FUNÇÃO DA TERCEIRA THREAD
void * minha_thread_3(void *apelido) {
	sleep(1);
	while (1) {
		printf(" 3\n");
		sleep(2);
	}
	pthread_exit(NULL);
}

//FUNÇÃO DE CONFIGURAÇÃO DAS PORTAS PARA LED
int portConfig(int argc, char *argv[]){
	int fd;

  // export GPIO
  fd = open("/sys/class/gpio/export", O_WRONLY);
  write(fd, "50", 2);
  close(fd);

  // Configure as output
  fd = open("/sys/class/gpio/gpio50/direction", O_WRONLY);
  write(fd, "out", 3);
  close(fd);

  // Blink GPIO once
/*
  fd = open("/sys/class/gpio/gpio50/value", O_WRONLY | O_SYNC);
  write(fd, "0", 1);
  usleep(1000000);
  write(fd, "1", 1);
  close(fd);
*/
  return EXIT_SUCCESS;
}

int calculoTensao(posicaoFinal, posicaoInicial){
	erro = math.abs(posicaoFinal - posicaoInicial);
	ddp = erro*coef + correcao;
}

/////////////////////////////////////////////////MAIN//////////////////////////////////////////////////

int main(int argc, char *argv[]) {

	pthread_create (&id1, NULL , (void *) minha_thread_1, NULL);

	pthread_create (&id2, NULL , (void *) minha_thread_2, NULL);

	pthread_create (&id3, NULL , (void *) calculoTensao, NULL);

	while (erro < 10^-6);
	return 0;
}
