#!/bin/bash
#simple script to update firefox. Written by CMT using help from stackexchange
# released under GNU GPLv3

cd /home/tcaleb/Downloads/firefox-versions
rm -R /home/tcaleb/Downloads/firefox-versions/*
echo "Downloading current version of Firefox:"
curl -Lo firefox.tar.bz2 'https://download.mozilla.org/?product=firefox-latest&os=linux64&lang=en-US' # pulls current firefox source from Mozilla
echo "Decompressing:"
tar -xvf firefox.tar.bz2
echo "Managing Files..."
rm -R /opt/firefox.old # Kills old backup
mv /opt/firefox /opt/firefox.old #Backup current running config
cp -R /home/tcaleb/Downloads/firefox-versions/firefox /opt/ # replace files w/ new version
echo "Update Completed"
