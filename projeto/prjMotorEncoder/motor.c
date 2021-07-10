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
double posicaoFinal, ddp, erro;
double coef, correcao;

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

//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
int saidaProMotor(posicaoAtual, portaComunicacao, portaSaida, ....){
	s = posicao;
	ptc = porta;
	pts = portaS;

	.
	.
	.

	return(dpp)
}


int envio(dauibfailsdf){
	pegar o valor de tensao
	manda para a porta X
}

int thread2(){
	while(true){
		envio(tensao, porta);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
Sensor
Controlador
Atuador

Interface


thread 1 (comunicacao sensor-controlador)
	coletar dados/valores do sensor (constantemente)
	transformar os dados obtidos (numero/decimal)
	compreender o significado do sinal (posicao absoluta x relativa)
	enviar posicao para o controlador

	matematica/modelagem do controlador
	calcular o controle (|posicao no tempo 1 - posicao desejada| = erro)
	baseado no erro, fazer o calculo de proporcionalidade para a tensao a ser enviada pro motor

thread 2 (comunicacao controlador-atuador)
	coletar dados/valores do controlador
	transformar os dados obtidos
	compreender o significado do dado
	enviar o valor de saida para o atuador/motor
	
	tal que, quando calculado o valor de saida, o valor do sensor atualiza, refazendo o calculo e mandando-o de volta

protocolo de comunicao em cam, a especificar as portas dos arquivos etc
enviando: caso o motor tenha apenas uma ponte H, mandar tensao (e a ponte H faz o calculo proprio, mexendo o motor); caso haja um microcontrolador, enviar um .txt (ditando o que deve ser feito)

