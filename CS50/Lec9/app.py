from flask import Flask, render_template, request

# __name__ is a special variable that refers to the current file's name
app = Flask(__name__)

@app.route("/")
def index():
    return "hello, world"