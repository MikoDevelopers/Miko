#include <iostream>
#include <fstream>
#include <string>
#include <map>

/*
#include "MikoStruct.h"
#include "API/Telegram/TelegramAPI.h"
#include "API/Instagram/InstagramApi.h"
#include "API/Discord/DiscordApi.h"
#include "API/Vk/VkApi.h"
*/       
#include "Read/ReadMikoFile.h"



int main(int argc, char *argv[])
{
    std::string MikoFileOutput = ReadMikoFileFunction("main.miko");
    


    return 0;
}