# Projeto acionamento de Motor e coleta de dados de enconder via barramento CAN e EPOS

Antes de usar a comunicação com a EPOS precisa instalar algumas ferramentas

```sh
~$ sudo apt-get update
~$ sudo apt-get upgrade
```
Segue ess tutorial para instalar CANopen
https://opensource.lely.com/canopen/docs/installation/

```sh
~$ sudo apt-get update
~$ git clone https://github.com/CANopenNode/CANopenDemo.git
~$ cd CANopenDemo
~/CANopenDemo/$ git submodule update --init --recursive
```
Se precisar atualizar depois
```sh
~$ cd CANopenDemo
~/CANopenDemo/$ git pull
~/CANopenDemo/$ git submodule update --init --recursive
```
Agora é "buildar" e rodar em no mínimo 4 terminais distintos

> Terminal 1
```sh
# Adicionar a função que vai fazer a comunicação
~$ cd CANopenDemo/CANopenLinux/cocomm/
~CANopenDemo/CANopenLinux/cocomm/$ make 
~CANopenDemo/CANopenLinux/cocomm/$ sudo make install
~CANopenDemo/CANopenLinux/cocomm/$ cd
# Inicializar o barramento virtual can0 (para teste)
~$ sudo modprobe vcan
~$ sudo ip link add dev can0 type vcan
~$ sudo ip link set up can0
# Ouvir tudo o que é enviado ao barramento
~$ candump can0
```

> Terminal 2
```sh
# Compilar e criar o nó "master"
~$ cd CANopenDemo/CANopenLinux/
~/CANopenDemo/CANopenLinux/$ make
~/CANopenDemo/CANopenLinux/$ rm *.persist
~/CANopenDemo/CANopenLinux/$ ./canopend can0 -i 1 -c "local-/tmp/CO_command_socket"
# Usando o canopend pode se criar diversos nós  "./canopend (Barramento -i id-Nó)"
```

> Terminal 3
```sh
# Compilar e criar o nó "slave"
~$ cd CANopenDemo/demo/
~/CANopenDemo/demo/$ make
~/CANopenDemo/demo/$ rm *.persist
~/CANopenDemo/demo/$ ./demoLinuxDevice can0
```

> Terminal 4
```sh
#aqui é onde você vai passar os commandos via cocomm
~$ cocomm "help"
```

Nos tutoriais explicam certinho e passo a passo, o que é cada função, como usar, quais parametros, o que cada valor significa.

# Links Possivelmente úteis

> Git com programas e documentação para entender o básico do CANopen aplicado for dummies<br>
Interno a esse repositório existe diversos outros que são base, como o CANopenLinux, por ser mais completo, é o que recomendo.
https://github.com/CANopenNode/CANopenDemo

> READ.me bem simplificado de tutorial para ver se a instalação tá ok <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/README.md

> Após brincar um pouco faça o teste global das ferramentas <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/test/README.md

> Configurar os nós e dar nome a eles com LSS <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/LSS.md

> Finalizar a configuração dos nós via comandos SDO <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/SDO.md

> Teste de comunicação entre nós e master PDO <br>
https://github.com/CANopenNode/CANopenDemo/blob/master/tutorial/PDO.md

# ###############################################################################################################################################################

# GUI para IHM

Foi o primeiros teste de criação de uma Interface Humano Máquina, usando Gnu ToolKit, os tutorias em que aprendi a usar se encontram no link https://developer.gnome.org/gtk3/stable/gtk-getting-started.html

# Links possivelmente úteis

> Tutoriais Toradex <br>
https://developer.toradex.com/getting-started/module-3-hardware-peripherals/basic-gpio-usage-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux

> Tutoriais GTK <br>
https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
https://developer.gnome.org/gtk4/stable/gtk-getting-started.html

>git oficial de GTK <br>
https://gnome.pages.gitlab.gnome.org/gtk/gtk4/

> Manuais <br>
https://developer.gnome.org/references
https://developer.gnome.org/gtk4/stable/
https://developer.gnome.org/gtk3/stable/

> Resumo <br>
https://developer.gnome.org/platform-overview/unstable/tech-gtk.html.en

Instalação do GTK
Vai se necessário o uso do ninja e do meson
```sh
~$ sudo apt-get install python3 python3-pip python3-setuptools python3-wheel ninja-build
~$ sudo su
# pip3 install meson
```

Faça download dos arquivos
```sh
~$ git clone https://gitlab.gnome.org/GNOME/gtk.git
~$ cd gtk/
~$ meson setup --prefix /opt/gtk builddir
~$ cd builddir
~$ ninja
~$ sudo su
# ninja install
```
