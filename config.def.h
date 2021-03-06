/* macro for conveniently specifying pathu and pathc below */
#define PATH(name)                      "/home/kev/Programs/dwmblocks/blocks/"name

/* buffer size for capturing output of the programs used for updating blocks */
#define CMDOUTLENGTH                    50

/* DELIMITERENDCHAR must be less than 32.
 * At max, DELIMITERENDCHAR - 1 number of clickable blocks are allowed.
 * Raw characters larger than DELIMITERENDCHAR and smaller than ' ' in ASCII
   character set can be used for signaling color change in status.
 * The character corresponding to DELIMITERENDCHAR + 1 ('\x0b' when
   DELIMITERENDCHAR is 10) will switch the active colorscheme to the first one
   defined in colors array in dwm's config.h and so on.
 * If you wish to change DELIMITERENDCHAR, don't forget to update its value in
   dwm.c and color codes in your pathu programs. */
#define DELIMITERENDCHAR               12 

/* delimiter specified as an array of characters
 * (don't remove DELIMITERENDCHAR at the end) */
static const char delimiter[] = { ' ', ' ', ' ', DELIMITERENDCHAR };

#include "block.h"

/* If interval of a block is set to 0, the block will only be updated once at
   startup.
 * If interval is set to a negative value, the block will never be updated in
   the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the
   block.
 * Signal must be less than DELIMITERENDCHAR for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be
   delivered first. */

/* pathu - path of the program whose output is used as status text of the block
           (output of the program should be a single line of text with at most
            one newline character at the end)
 * pathc - path of the program used for handling clicks on the block */

/* 1 interval = INTERVALs seconds, INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0

static Block blocks[] = {
/*      pathu                           pathc                           interval        signal */
        //{ PATH("cpu_temp.sh"),          PATH("cpu_temp_button.sh"),     1,              4},
		    //{ PATH("forecast.sh"),          PATH("forecast.sh"),            1800,           8},*/
        { PATH("calendar.sh"),          PATH("calendar.sh"),              30,             1},
        { PATH("volume.sh"),            PATH("volume.sh"),       		      0,              10},
        { PATH("cpu.sh"),          		  PATH("cpu.sh"),     			        1,              7},
		    { PATH("memory.sh"),			      PATH("memory.sh"),							  10,				      5},
		    { PATH("internet.sh"),			    PATH("internet.sh"),	 		        10,				      6},
		    { PATH("brightness.sh"),		    PATH("brightness.sh"),		        0,				      4},
        { PATH("battery.sh"),           PATH("battery_button.sh"),        30,             3},
        { NULL } /* just to mark the end of the array */
};
