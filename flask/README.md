```
FLASK_APP=main.py flask run --host=0.0.0.0
```

Add below to /etc/crontab for auto-starting a flask server.
```
@reboot root /bin/su -c "cd /home/zsc/cruiserbot/flask/ && FLASK_APP=/home/zsc/cruiserbot/flask/main.py flask run --host=0.0.0.0" - zsc
```
