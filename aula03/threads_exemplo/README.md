Após bater muito a cabeça, ajeitei o arquivo CMakeList.txt, então para 
compilar o programa threads.c podem ser feitas duas formas diferentes

Diferença entre GCC e CMake (minha opinião):<br>
GCC é mais fácil e mais intuitivo, porém quando for necessário diversas
 bibliotecas acaba se tornando fácil errar as chamadas. Já o CMake resolve 
bem esse problema, porém ele não é intuitivo para adicionar novas bibliotecas
ou mesmo fazer o uso de bibliotecas já conhecidas (math.h).


# Usando GCC
```sh
$ gcc threads_exemplo.c -o threads_exemplo -lm -lpthread
$ ./threads_exemplo
```

# Usando CMake 
```sh
$ cmake .
$ make
$ ./threads_exemplo
```
