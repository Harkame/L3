#!/bin/bash

mkdir e5;
chmod 700 e5;
touch e5/e5.txt;

chmod u-l  e5;
echo "Yolo" >> e5/e5.txt;

chmod u-x e5;
mv e5/e5.txt e5/e5_bis.txt

chmod u-r e5;
rm e5/e5.txt;
