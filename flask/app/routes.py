from app import app
import random

@app.route('/')
@app.route('/index')
def index():
    return "Hi there {}!".format(random.randint(0, 10))

@app.route('/can_recycle')
def can_recycle():
    print('can recycle')
    return ""

@app.route('/cant_recycle')
def cant_recycle():
    print('can recycle')
    return ""

@app.route('/clean')
def clean():
    print('clean')
    return ""
