#!/bin/bash

#Force to run as root
if [ "$(id -u)" != "0" ]; then
   echo "[ERROR] This script must be run as root. Run as:" 1>&2
   echo "    sudo $0" 1>&2
   exit 1
fi

#Update Repositories & Packages
aptitude update
aptitude upgrade -y

#Install new packages
aptitude install -y doxygen graphviz qt4-dev-tools libqt4-dev libqt4-core libqt4-gui qt4-doc-html

#Clean cach
aptitude -y clean
aptitude -y autoclean
