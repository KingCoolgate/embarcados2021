#!/bin/sh

#Inicializa CAN BUS
sudo modprobe vcan
sudo ip link add dev can0 type vcan
sudo ip link set up can0

#Cria nós virtuais
gnome-terminal -- /bin/bash /home/joao-ishida/embarcados2021/projeto/prjMotorEncoder/crtNd1.sh
gnome-terminal -- /bin/bash /home/joao-ishida/embarcados2021/projeto/prjMotorEncoder/crtNd2.sh

#Configura o Nó 1
#RPDO
cocomm "set node 1"
cocomm "[101] w 0x1400 1 x32 0x00000201"
cocomm "[102] w 0x1400 2 u8 255"
cocomm "[103] w 0x1400 5 u16 0"
#TPDO
cocomm "[104] w 0x1800 1 x32 0x40000181"
cocomm "[105] w 0x1800 2 u8 255"
cocomm "[106] w 0x1800 3 u16 0"
cocomm "[107] w 0x1800 5 u16 0"
cocomm "[108] w 0x1800 6 u8 0"

#Configura o nó 2
#RPDO
cocomm "set node 2"
cocomm "[201] w 0x1400 1 x32 0x00000201"
cocomm "[202] w 0x1400 2 u8 255"
cocomm "[203] w 0x1400 5 u16 0"
#TPDO
cocomm "[204] w 0x1800 1 x32 0x40000181"
cocomm "[205] w 0x1800 2 u8 255"
cocomm "[206] w 0x1800 3 u16 0"
cocomm "[207] w 0x1800 5 u16 0"
cocomm "[208] w 0x1800 6 u8 0"
