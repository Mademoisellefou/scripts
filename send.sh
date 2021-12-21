#!/bin/sh
####################################################
# DESC:Send SMS via ASPSMS gateway from OpenWrt
####################################################
# HOW TO SETUP
# SOAP Web Service core interface to connect to the ASPSMS System
# aspsms.sh <mobile-number> <text to send ,spaced get replaced by> 
PATH=/usr/bin:/usr/sbin:/bin:/sbin:/etc/config/bin
export PATH
UserKey='AAABBBCC'
Password='123'
FROM=SenderName
MOBILE="$1"
SMS="$2"
SMS="`echo $SMS | tr ' ' '_'`"
echo SMS:$SMS
echo MOBILE: $MOBILE    
curl -k "https://soap.aspsms.com/aspsmsx.asmx/SimpleTextSMS?UserKey=$UserKey&Password=$Password&Recipient=$MOBILE&Originator=$FROM&MessageText=$SMS"


