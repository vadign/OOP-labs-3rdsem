#include "checks.h"

bool checks::isLetter(char symbToCheck) {
    return (symbToCheck >= 'a' && symbToCheck <= 'z') || (symbToCheck >= 'A' && symbToCheck <= 'Z');
}

bool checks::isNumber(char symbToCheck) {
    return (symbToCheck >= '0' && symbToCheck <= '9');
}

