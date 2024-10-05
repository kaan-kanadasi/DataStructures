# cd CS50    cd Lec9    flask run

from flask import Flask, render_template, request

# __name__ is a special variable that refers to the current file's name
app = Flask(__name__)

@app.route("/")
def index():
    if "name" in request.args:
        name = request.args["name"]
    else:
        name = "world"
    return render_template("index.html", placeholder=name)