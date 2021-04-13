/*
    File for including:
        * header of funcktion
        * all libs
        * API
        * methods of variables
*/

#define include_foo
//#define include_lib
//#define include_var_methods

const int NUM_OF_FUNCKTIONS = 8;
const int NUM_OF_KEY_WORDS = 25;
const int ALL_OF_KEY = NUM_OF_FUNCKTIONS + NUM_OF_KEY_WORDS;


#ifdef include_foo
    #include "../Functions/print.hpp"
//    #include "../Functions/input.h"
    #include "../Functions/len.h"
   // #include "../Functions/changeType.h"
#endif

#ifdef include_lib
    #include "Libs/Math/MathLib.h"
    #include "Libs/Time/TimeLib.h"
    #include "Libs/Random/RandomLib.h"
    #include "Libs/Os_Sys/Os_SysLib.h"
    #include "Libs/Requests/RequestsLib.h"

    #include "API/Discord/DiscordApi.h"
    #include "API/Instagram/InstagramApi.h"
    #include "API/Telegram/TelegramApi.h"
    #include "API/Vk/VkApi.h"
#endif

#ifdef include_var_methods
    #include "Methods/int/IntMethods.h"
    #include "Methods/str/StrMethods.h"
    #include "Methods/bool/BoolMethods.h"
    #include "Methods/list/ListMethods.h"
    #include "Methods/float/FloatMethods.h"
#endif