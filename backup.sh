#!/bin/bash
# DESC: multiple backup files in a dir
DATE= $(date '+%Y%m%d%H%M')
ID=aeos-bkp
BDIR=/home/backup/aeos
SUFF=.tar.gz
GEN=10
cd $BDIR
for BKP in $(ls -l | grep $SUFF | grep -v $ID)
do 
mv $BKP $DATE-$ID-$BKP
done
mkdir tmp
for SAVE in $(ls -l | grep $SUFF | grep $ID | cut -d- -f1 | sort -un | tail -n$GEN)
do
    mv $SAVE-$ID* tmp
done
rm -f *ID*$UFF
mv tmp/* ./
rm -r tmp



