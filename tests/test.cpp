#define CATCH_CONFIG_MAIN

#include "../include/chatbot.h"
#include "catch2/catch.hpp"

TEST_CASE("ChatBot Tests", "[ChatBotTests]") {
  SECTION("Default Constructor Empty") {
    ChatBot chat_bot;
    CHECK(chat_bot.GetImageHandle() == nullptr);
  }
}