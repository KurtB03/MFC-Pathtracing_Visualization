#! /bin/bash
COMMIT=$(git rev-parse --short HEAD)
NAME=Isonoe
VERSION=$NAME-$COMMIT

ARGS="--metadata pagetitle=$NAME README.md -s -o Download/Artikel/$VERSION.html"
 
pandoc -f gfm -c pandoc.css $ARGS
