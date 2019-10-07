from flask import Flask

app = Flask(__name__)
app.config['SEND_FILE_MAX_AGE_DEFAULT'] = 0

'''
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate, public, max-age=0"
    response.headers["Expires"] = '0'
    response.headers["Pragma"] = "no-cache"
    return response
'''

from app import routes
