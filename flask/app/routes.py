from app import app
import random

@app.route('/')
@app.route('/index')
def index():
    return "Hi there {}!".format(random.randint(0, 10))
