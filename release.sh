#!/bin/bash
rm -rf release
mkdir -p release

cp -rf sc *.{hpp,cpp,txt,json} LICENSE release/

mv release score-addon-sc
7z a score-addon-sc.zip score-addon-sc
