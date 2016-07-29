from flask import Flask,render_template
from scrap_bbc import scrap_it
app = Flask(__name__)

@app.route('/')
def index():
    gossip = scrap_it()
    return render_template('base.html',pages=gossip)


if __name__=='__main__':
    app.run()
