#ifndef RECOGNIZER_H
#   include "recognizer.h"
#endif

#ifndef SCANNER_H
#   include "scanner.c"
#endif

#ifndef _STDBOOL_H
#   include <stdbool.h>
#endif

bool recognize(char source[]){
    for(int iter = 0;
    source[iter] != '\0';
    iter += 1){
        // check tokens
        if(getCharType(source[iter]) != token);
        else
            if(getCharType(source[iter]) == -1)
                return false;
    }

    return true;
}