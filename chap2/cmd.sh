#!/bin/bash
dnf -y update
reboot
dnf -y install clamav clamav-update
dnf -y install yum-utils rpm-build
yumdownloader --source clamav
rpm --checksig clamav-0.99.2-1.fc25.src.rpm
rpm -ivh clamav-0.99.2-1.fc25.src.rpm
yum-builddep -y clamav-0.99.2-1.fc25.src.rpm ~/rpmbuild/SPECS/clamav.spec
rpmbuild -bb ~/rpmbuild/SPECS/clamav.spec
dnf -y install clamav-devel
cd ~/rpmbuild/BUILD/clamav-0.99.2/examples/
gcc -Wall ex1.c -o ex1 -lclamav
sed -i -e 's/^Example/#Example/' /etc/freshclam.conf
freshclam

dnf -y install kernel-devel ncurses-devel
dnf -y install subversion
mkdir ~/SVN
cd ~/SVN/
svn checkout https://svn.osdn.net/svnroot/tomoyo/
svn checkout https://svn.osdn.net/svnroot/akari/
svn checkout https://svn.osdn.net/svnroot/caitsith/
