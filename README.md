# Matéria de Embarcados

Nesse repositório é para fazermos e mostrar os andamentos do projeto. 

Aula 01 - Estrutura de embarcado, linux e programa de aula.

Aula 02 - Compilação, arquitetura arm e git.

Aula 03 - Uso de C, compiladores, threads, acesso remoto e cross compiling.

Aula 04 - Cross compiling prática, explicação de threads, projetos de matéria.

Aula 04 - Atualização dos arquivos, reajustando os branches e commits. Funfou, mas via gambiarras.


Links possivelmente úteis

>Tutoriais
https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
https://developer.gnome.org/gtk4/stable/gtk-getting-started.html

>git oficial
https://gnome.pages.gitlab.gnome.org/gtk/gtk4/

>Manuais
https://developer.gnome.org/references
https://developer.gnome.org/gtk4/stable/
https://developer.gnome.org/gtk3/stable/

>Resumo
https://developer.gnome.org/platform-overview/unstable/tech-gtk.html.en

>Instalação do GTK
Faça download dos arquivos
git clone https://gitlab.gnome.org/GNOME/gtk.git

>>Vai se necessário o uso do ninja e do meson
$ sudo apt-get install python3 python3-pip python3-setuptools python3-wheel ninja-build

$ sudo su

# pip3 install meson

$ cd gtk/

$ meson setup --prefix /opt/gtk builddir

$ cd builddir

$ ninja

$ sudo su

# ninja install
