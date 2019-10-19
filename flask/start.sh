#!/bin/bash

### BEGIN INIT INFO
# Provides:             cruiserbot
# Required-Start:       $remote_fs $syslog
# Required-Stop:        $remote_fs $syslog
# Default-Start:        2 3 4 5
# Default-Stop:         
# Short-Description:    OpenBSD Secure Shell server
### END INIT INFO

#[[ -x /dev/ttyACM0 ]] || sudo chmod 777 /dev/ttyACM0
FLASK_APP=main.py flask run --host=0.0.0.0
