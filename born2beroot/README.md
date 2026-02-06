*This project has been created as part of the 42 curriculum by
elguiduc.*

# Born2beroot

## Description

This project consist of setting up you first server, installing the minimum of 
services.  For this reason, a graphical interface is of no
use here. It is therefore forbidden to install X.org, wayland, or
any other equivalent graphics server.

### Debian/Rocky Linux
I chose the latest stable version of Debian instead of Rocky Linux because this is my 
very first approach to the world of virtual machine and system administration.

### AppArmor/SELinux
AppArmor and SELinux are both Mandatory Access Control (MAC) systems that enhance Linux security by restricting application behavior beyond traditional permissions.
AppArmor uses path-based rules, defining what files and directories an application can access based on its filesystem path (e.g., /usr/bin/firefox). 
SELinux uses label-based policies, assigning security contexts (labels) to files, processes, and ports.  Access is granted only if a policy rule matches the source and target labels.

### UFW/firewalld

UFW (Uncomplicated Firewall) and firewalld are both user-friendly front-ends for Linux's underlying packet filtering systems.
UFW: Default on Ubuntu and Debian-based systems. It is simple and ideal for beginners or basic server setups.
Firewalld: Default on RHEL, Fedora, CentOS, and openSUSE.  Built for dynamic environments with multiple network interfaces, such as laptops switching between home, work, and public Wi-Fi.

### VirtualBox/UTM
They are both free, open-source virtualizations tools, they differ in performance, featurea and compatibility.
UTM excels on Apple Silicon Macs (M1/M2/M3), while VirtualBox runs slower on Apple Silicon due to virtualization overhead and is better optimized for Intel-based Macs.
UTM offers a simple macOS-native GUI, making setup easy, while VirtualBOx provides more advanced features like snapshots, shared folders...
UTM supports macIO and iOS, but as limited guest OS support for Linux distros. On the other hand, VirtualBox supports Windows, macOS, Linux and Solaris.

## Instructions

### Requirements

-   create at least 2 encrypted partitions using LVM.
-   SSH service running on the port 4242. To connect:

		elguiduc@c1r5p10:~$ ssh elguiduc@localhost -p 4241

-	Configure your operating system with the UFW firewall.
-	The hostname of your virtual machine must be your login ending with 42
-	You have to implement a strong password policy.
-	You have to install and configure sudo following strict rules.
-	In addition to the root user, a user with your login as username has to be 
	present. This user has to belong to the user42 and sudo groups.
-	Create a script called monitoring.sh developed in bash displaying a series of
	informations


## Bonus part

The bonus part requires to create the following structure:

	elguiduc@elguiduc42:~$ lsblk
	NAME                    MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINTS
	sda                       8:0    0   30G  0 disk  
	├─sda1                    8:1    0  476M  0 part  /boot
	├─sda2                    8:2    0    1K  0 part  
	└─sda5                    8:5    0 29.5G  0 part  
	└─sda5_crypt          	254:0    0 29.5G  0 crypt 
		├─LVMGroup-root     254:1    0  9.3G  0 lvm   /
		├─LVMGroup-swap     254:2    0  2.1G  0 lvm   [SWAP]
		├─LVMGroup-home     254:3    0  4.7G  0 lvm   /home
		├─LVMGroup-var      254:4    0  2.8G  0 lvm   /var
		├─LVMGroup-srv      254:5    0  2.8G  0 lvm   /srv
		├─LVMGroup-tmp      254:6    0  2.8G  0 lvm   /tmp
		└─LVMGroup-var--log 254:7    0  3.7G  0 lvm   /var/log
	sr0                      11:0    1 1024M  0 rom  

It also requires to set up a functional WordPress website with the following
services: lighttpd, MariaDB, and PHP.

You have to set up a service of your choice that you think is useful (NGINX / Apache2 excluded!).

I chose the SFTP (SSH File Transfet Protocol) service. It provides a secure way to 
transfer files securely over a network. 
With this service you can upload and download files from your VM and from your local machine. 
To connect:

	elguiduc@c1r5p10:~$ sftp -P 4241 sftpuser@127.0.0.1

To upload a file:

	sftp> put Documents/prova_host.txt 
	Uploading Documents/prova_host.txt to /wp-content/uploads/prova_host.txt
	prova_host.txt                                100%   34     5.9KB/s   00:00 

To download a file:

	sftp> get buongiorno.txt 
	Fetching /wp-content/uploads/buongiorno.txt to buongiorno.txt
	buongiorno.txt                                100%   11     2.9KB/s   00:00  

## Resources

-   The 42 subject PDF for Bornto2beroot.
-	https://noreply.gitbook.io/born2beroot
-	https://github.com/Vikingu-del/Born2beRoot?tab=readme-ov-file
-	https://sftpcloud.io/learn/linux/setting-up-and-configuring-sftp-server-debian
-	https://www.digitalocean.com/community/tutorials/how-to-use-sftp-to-securely-transfer-files-with-a-remote-server