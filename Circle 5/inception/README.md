Settings
Virtual machine based debian (bookworm)

0. add $USER in sudo group
-> su -
-> usermod -aG sudo hyeondle
1. /etc/resolv.conf
-> add "nameserver 8.8.8.8"
2. /etc/hosts
-> add "127.0.0.1 hyeondle.42.fr"
3. /home/hyeondle/
-> add ./data/db, ./data/wordpress
-> chmod 775 db, wordpress
4. install docker
sudo apt update
sudo apt install -y curl
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
sudo usermod -aG docker $USER
