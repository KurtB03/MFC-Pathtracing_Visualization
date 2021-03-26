#! /bin/bash
COMMIT=$(git rev-parse --short HEAD)
NAME=Tee
VERSION=$NAME-$COMMIT
mv Download/Artikel/*.pdf Download/Artikel/old/
pandoc --pdf-engine=xelatex README.md -o Download/Artikel/$VERSION.pdf
