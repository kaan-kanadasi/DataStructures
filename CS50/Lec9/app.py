# cd CS50    cd Lec9    flask run

from flask import Flask, render_template, request

# __name__ is a special variable that refers to the current file's name
app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)