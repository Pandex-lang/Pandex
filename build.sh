#!/usr/bash

# if you don't can use of make or not successfull
# and if you are using linux execute this Bash file
# and if you are using Windows execute the build.cmd
# file 
# <<How Execute>>
# open terminal & write ```bash build.sh``` or ```sh build.sh```

cc='gcc'
program="Pandex.c"
#flags=''
convert="Pandex"

$cc $flags -o $convert;
export PATH=$PATH:pwd