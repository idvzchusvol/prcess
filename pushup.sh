#!/bin/bash

xelatex process.tex

git add *
git add .gitignore

git commit -m "Up Up Up"

git push
