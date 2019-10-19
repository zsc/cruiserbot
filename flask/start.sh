#!/bin/bash

#[[ -x /dev/ttyACM0 ]] || sudo chmod 777 /dev/ttyACM0
cd /home/zsc/cruiserbot/flask/
FLASK_APP=/home/zsc/cruiserbot/flask/main.py flask run --host=0.0.0.0
