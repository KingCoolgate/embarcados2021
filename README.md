# Matéria de Embarcados

Nesse repositório é para fazermos e mostrar os andamentos do projeto.

Aula 01 - 12/04 - Estrutura de embarcado, linux e programa de aula. <br>
Aula 02 - 19/14 - Compilação, arquitetura arm e git. <br>
Aula 03 - 26/04 - Uso de C, compiladores, threads, acesso remoto e cross compiling. <br>
Aula 04 - 03/05 - Threads e programação em paralelo <br>
Aula 05 - 05/05 - Consideração de Hardware <br> 
Aula 06 - 10/05 - Programação de Kernel <br>
Aula 07 - 17/05 - Uso de C, compiladores, cross compiling e threads.  <br>
Aula 08 - 24/05 - Threads (conceito de semaphoro- producer/consumer), portas do embarcados, cross-compiling. <br>
Aula 09 - 31/05 - Redes. <br>
Aula 10 - 07/06 - Server e client. <br>
Aula 11 - 14/06 - Server e client 2. <br>
Aula 12 - 21/06 - Comunicação CAN. <br>
Aula 13 - 28/06 - Considerações de Projetos embarcados e apresentações de ideias. <br>
Aula 14 - 05/07 - Considerações de Projetos embarcados e apresentações de ideias de grupos restantes e resolução de duvidas. <br>
Aula 15 - 12/07 - Prova. <br>
Aula 16 - 19/07 - Apresentação de projeto <br>

# Links possivelmente úteis

>Tutoriais Toradex <br>
https://developer.toradex.com/getting-started/module-3-hardware-peripherals/basic-gpio-usage-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux

>Tutoriais GTK <br>
https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
https://developer.gnome.org/gtk4/stable/gtk-getting-started.html

>git oficial de GTK <br>
https://gnome.pages.gitlab.gnome.org/gtk/gtk4/

>Manuais <br>
https://developer.gnome.org/references
https://developer.gnome.org/gtk4/stable/
https://developer.gnome.org/gtk3/stable/

>Resumo <br>
https://developer.gnome.org/platform-overview/unstable/tech-gtk.html.en

Instalação do GTK
Vai se necessário o uso do ninja e do meson
```sh
$ sudo apt-get install python3 python3-pip python3-setuptools python3-wheel ninja-build
$ sudo su
# pip3 install meson
```

Faça download dos arquivos
```sh
$ git clone https://gitlab.gnome.org/GNOME/gtk.git
$ cd gtk/
$ meson setup --prefix /opt/gtk builddir
$ cd builddir
$ ninja
$ sudo su
# ninja install
```
