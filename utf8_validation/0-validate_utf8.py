#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """
    A method that determines if a given data
    set represents a valid UTF-8 encoding.
    """
    number_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6
    for number in data:
        mask3 = 1 << 7
        if number_bytes == 0:
            while mask3 & number:
                number_bytes += 1
                mask3 = mask3 << 1
            if number_bytes == 0:
                continue
            if number_bytes == 1 or number_bytes > 4:
                return False
        else:
            if not(mask1 & number and not(mask2 & number)):
                return False
        number_bytes -= 1
    return number_bytes == 0
