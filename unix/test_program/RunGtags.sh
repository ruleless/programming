#!/bin/bash

make &&
sudo make install &&
make clean &&
cd .. &&
schedule 5 gtags -i
