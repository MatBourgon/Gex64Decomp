#define ASWHITESPACE    0x01
#define ASUPPERCASE     0x02
#define ASLOWERCASE     0x04
#define ASDIGIT        0x08
#define ASHEXLETTER     0x10
#define ASCOMMAND       0x20
#define ASSYMBOL        0x40

static char asciiMap[256] = {
    ASCOMMAND,                  // 00 NULL
    ASCOMMAND,                  // 01 HEADING START
    ASCOMMAND,                  // 02 TEXT START
    ASCOMMAND,                  // 03 TEXT END
    ASCOMMAND,                  // 04 TRANSMISSION END
    ASCOMMAND,                  // 05 ENQUIRY
    ASCOMMAND,                  // 06 ACKNOWLEDGE
    ASCOMMAND,                  // 07 BELL
    ASCOMMAND,                  // 08 BACKSPACE
    ASCOMMAND | ASWHITESPACE,   // 09 HORIZONTAL TAB
    ASCOMMAND | ASWHITESPACE,   // 0A LINE FEED
    ASCOMMAND | ASWHITESPACE,   // 0B VERTICAL TAB
    ASCOMMAND | ASWHITESPACE,   // 0C FORM FEED
    ASCOMMAND | ASWHITESPACE,   // 0D CARRIAGE RETURN
    ASCOMMAND,                  // 0E SHIFT OUT
    ASCOMMAND,                  // 0F SHIFT IN

    ASCOMMAND,                  // 10 DATA LINK ESCAPE
    ASCOMMAND,                  // 11 DEVICE CONTROL 1
    ASCOMMAND,                  // 12 DEVICE CONTROL 2
    ASCOMMAND,                  // 13 DEVICE CONTROL 3
    ASCOMMAND,                  // 14 DEVICE CONTROL 4
    ASCOMMAND,                  // 15 NEGATIVE ACKNOWLEDGE
    ASCOMMAND,                  // 16 SYNCHRONOUS IDLE
    ASCOMMAND,                  // 17 END OF TRANSMISSION BLOCK
    ASCOMMAND,                  // 18 CANCEL
    ASCOMMAND,                  // 19 END OF MEDIUM
    ASCOMMAND,                  // 1A SUBSTITUTE
    ASCOMMAND,                  // 1B ESCAPE
    ASCOMMAND,                  // 1C FILE SEPARATOR
    ASCOMMAND,                  // 1D GROUP SEPARATOR
    ASCOMMAND,                  // 1E RECORD SEPARATOR
    ASCOMMAND,                  // 1F UNIT SEPARATOR

    ASWHITESPACE,               // 20 SPACE
    ASSYMBOL,                   // 21 EXCLAMATION MARK !
    ASSYMBOL,                   // 22 DOUBLE QUOTE "
    ASSYMBOL,                   // 23 POUND SIGN #
    ASSYMBOL,                   // 24 DOLLAR SIGN $
    ASSYMBOL,                   // 25 PERCENTAGE SIGN %
    ASSYMBOL,                   // 26 AMPERSAND &
    ASSYMBOL,                   // 27 SINGLE QUOTE '
    ASSYMBOL,                   // 28 LEFT PARENTHESIS (
    ASSYMBOL,                   // 29 RIGHT PARENTHESIS )
    ASSYMBOL,                   // 2A ASTERISK *
    ASSYMBOL,                   // 2B PLUS +
    ASSYMBOL,                   // 2C COMMA ,
    ASSYMBOL,                   // 2D MINUS -
    ASSYMBOL,                   // 2E PERIOD .
    ASSYMBOL,                   // 2F FORWARD SLASH /

    ASDIGIT,                    // 30 NUMBER 0
    ASDIGIT,                    // 31 NUMBER 1
    ASDIGIT,                    // 32 NUMBER 2
    ASDIGIT,                    // 33 NUMBER 3
    ASDIGIT,                    // 34 NUMBER 4
    ASDIGIT,                    // 35 NUMBER 5
    ASDIGIT,                    // 36 NUMBER 6
    ASDIGIT,                    // 37 NUMBER 7
    ASDIGIT,                    // 38 NUMBER 8
    ASDIGIT,                    // 39 NUMBER 9
    ASSYMBOL,                   // 3A COLON :
    ASSYMBOL,                   // 3B SEMI-COLON ;
    ASSYMBOL,                   // 3C LEFT CHEVRON <
    ASSYMBOL,                   // 3D EQUAL =
    ASSYMBOL,                   // 3E RIGHT CHEVRON >
    ASSYMBOL,                   // 3F QUESTION MARK ?

    ASSYMBOL,                   // 40 COMMERCIAL AT @
    ASUPPERCASE | ASHEXLETTER,  // 41 UPPERCASE LETTER A
    ASUPPERCASE | ASHEXLETTER,  // 42 UPPERCASE LETTER B
    ASUPPERCASE | ASHEXLETTER,  // 43 UPPERCASE LETTER C
    ASUPPERCASE | ASHEXLETTER,  // 44 UPPERCASE LETTER D
    ASUPPERCASE | ASHEXLETTER,  // 45 UPPERCASE LETTER E
    ASUPPERCASE | ASHEXLETTER,  // 46 UPPERCASE LETTER F
    ASUPPERCASE,                // 47 UPPERCASE LETTER G
    ASUPPERCASE,                // 48 UPPERCASE LETTER H
    ASUPPERCASE,                // 49 UPPERCASE LETTER I
    ASUPPERCASE,                // 4A UPPERCASE LETTER J
    ASUPPERCASE,                // 4B UPPERCASE LETTER K
    ASUPPERCASE,                // 4C UPPERCASE LETTER L
    ASUPPERCASE,                // 4D UPPERCASE LETTER M
    ASUPPERCASE,                // 4E UPPERCASE LETTER N
    ASUPPERCASE,                // 4F UPPERCASE LETTER O

    ASUPPERCASE,                // 50 UPPERCASE LETTER P
    ASUPPERCASE,                // 51 UPPERCASE LETTER Q
    ASUPPERCASE,                // 52 UPPERCASE LETTER R
    ASUPPERCASE,                // 53 UPPERCASE LETTER S
    ASUPPERCASE,                // 54 UPPERCASE LETTER T
    ASUPPERCASE,                // 55 UPPERCASE LETTER U
    ASUPPERCASE,                // 56 UPPERCASE LETTER V
    ASUPPERCASE,                // 57 UPPERCASE LETTER W
    ASUPPERCASE,                // 58 UPPERCASE LETTER X
    ASUPPERCASE,                // 59 UPPERCASE LETTER Y
    ASUPPERCASE,                // 5A UPPERCASE LETTER Z
    ASSYMBOL,                   // 5B LEFT BRACKET [
    ASSYMBOL,                   // 5C BACKSLASH
    ASSYMBOL,                   // 5D RIGHT BRACKET ]
    ASSYMBOL,                   // 5E CARET ^
    ASSYMBOL,                   // 5F UNDERSCORE _

    ASSYMBOL,                   // 60 GRAVE `
    ASLOWERCASE | ASHEXLETTER,  // 61 LOWERCASE LETTER a
    ASLOWERCASE | ASHEXLETTER,  // 62 LOWERCASE LETTER b
    ASLOWERCASE | ASHEXLETTER,  // 63 LOWERCASE LETTER c
    ASLOWERCASE | ASHEXLETTER,  // 64 LOWERCASE LETTER d
    ASLOWERCASE | ASHEXLETTER,  // 65 LOWERCASE LETTER e
    ASLOWERCASE | ASHEXLETTER,  // 66 LOWERCASE LETTER f
    ASLOWERCASE,                // 67 LOWERCASE LETTER g
    ASLOWERCASE,                // 68 LOWERCASE LETTER h
    ASLOWERCASE,                // 69 LOWERCASE LETTER i
    ASLOWERCASE,                // 6A LOWERCASE LETTER j
    ASLOWERCASE,                // 6B LOWERCASE LETTER k
    ASLOWERCASE,                // 6C LOWERCASE LETTER l
    ASLOWERCASE,                // 6D LOWERCASE LETTER m
    ASLOWERCASE,                // 6E LOWERCASE LETTER n
    ASLOWERCASE,                // 6F LOWERCASE LETTER o

    ASLOWERCASE,                // 70 LOWERCASE LETTER p
    ASLOWERCASE,                // 71 LOWERCASE LETTER q
    ASLOWERCASE,                // 72 LOWERCASE LETTER r
    ASLOWERCASE,                // 73 LOWERCASE LETTER s
    ASLOWERCASE,                // 74 LOWERCASE LETTER t
    ASLOWERCASE,                // 75 LOWERCASE LETTER u
    ASLOWERCASE,                // 76 LOWERCASE LETTER v
    ASLOWERCASE,                // 77 LOWERCASE LETTER w
    ASLOWERCASE,                // 78 LOWERCASE LETTER x
    ASLOWERCASE,                // 79 LOWERCASE LETTER y
    ASLOWERCASE,                // 7A LOWERCASE LETTER z
    ASSYMBOL,                   // 7B LEFT BRACE {
    ASSYMBOL,                   // 7C PIPE |
    ASSYMBOL,                   // 7D RIGHT BRACE }
    ASSYMBOL,                   // 7E TILDE ~
    ASCOMMAND,                  // 7F DELETE

    // Extended ASCII range [128-255]
    0x00, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,  0x80, 0x00, 0x00, 0x00
};

int tolower(int c) {
    if (asciiMap[(c & 0xFF)] & ASUPPERCASE) {
        c += 0x20;
    }
    return c;
}
