[[ -x /dev/ttyACM0 ]] || sudo chmod 777 /dev/ttyACM0
FLASK_APP=main.py flask run --host=0.0.0.0
