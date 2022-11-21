#ifndef COLORS_H
# define COLORS_H

# define BLKB  "\e[40m"

# define YEL   "\e[0;33m"   // normal
# define HYEL  "\e[1;33m"   // bold or bright ???
# define DYEL  "\e[2;33m"   // dark
# define IYEL  "\e[3;33m"   // italics

# define GRN   "\x1B[32m"
# define HGRN  "\e[0;92m" // same as LGRN
# define LGRN  "\e[0;92m"


// WHITE
// THESE ARE ALL THE SAME
# define WHT   "\x1B[37m"	// bright
# define LWHT  "\e[0;37m"	// bright
# define BRWHT  "\e[0;97m"	// bright
# define WHT1  "\e[1;37m"	// bold
# define DWH   "\e[0;38m"   // dark white


# define LRD   "\x1B[31m" // light red
# define REDB  "\e[41m"	  // red background
# define SRD  "\e[91m"	  // strong red

// GREY
# define GRE  "\e[2;37m"	// dark white/grey
# define DWH   "\e[0;38m"   // dark white
# define LGRE  "\e[0;98m"   // same ???


# define BLU   "\e[0;34m"
# define LBLU   "\e[0;94m"
# define BLUB  "\e[1;34m"   // bold, light blue
# define BLUBH "\e[44m"

# define MAG   "\e[0;35m"
# define LMAG   "\e[0;95m"

# define CYN   "\x1B[36m"
# define RES   "\x1B[0m"

#endif
