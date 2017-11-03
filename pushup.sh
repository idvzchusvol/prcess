#!/bin/bash

xelatex process.tex

git add *

git commit -m "modify by Idvz"

git push
