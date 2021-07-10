# Matéria de Embarcados

Nesse repositório é para fazermos e mostrar os andamentos do projeto.

Aula 01 - Estrutura de embarcado, linux e programa de aula. <br>
Aula 02 - Compilação, arquitetura arm e git. <br>
Aula 03 - Uso de C, compiladores, threads, acesso remoto e cross compiling. <br>
Aula 04 - Consideração de Hardware <br>
Aula 05 - Programação de Kernel <br> 
Aula 06 - Threads (conceito de semaphoro- producer/consumer), portas do embarcados, cross-compiling <br>
Aula 07 - Threads (conceito de semaphoro- producer/consumer), portas do embarcados, cross-compiling <br>
Aula 08 - Redes <br>
Aula 09 - Server e client <br>
Aula 10 - Server e client 2 <br>
Aula 11 - Comunicação CAN <br>
Aula 12 - Considerações de Projetos embarcados <br>

# Links possivelmente úteis

>Tutoriais Toradex <br>
https://developer.toradex.com/getting-started/module-3-hardware-peripherals/basic-gpio-usage-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux

>Tutoriais GTK <br>
https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
https://developer.gnome.org/gtk4/stable/gtk-getting-started.html

>git oficial <br>
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
