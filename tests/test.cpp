#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "chatbot.h"

TEST_CASE("ChatBot Tests", "[ChatBotTests]") {
  const std::string kImageFile = "chatbot.png";
  SECTION("Default Constructor Empty") {
    ChatBot chat_bot;
    CHECK(chat_bot.GetImageHandle() == nullptr);
  }
  SECTION("Filename Constructor") {
    ChatBot chat_bot(kImageFile);
    CHECK(chat_bot.GetImageHandle()->IsOk());
  }
  SECTION("Copy Constructor") {
    ChatBot chat_bot(kImageFile);
    ChatBot chat_bot_copy(chat_bot);
    CHECK(chat_bot.GetImageHandle()->IsOk());
    CHECK(chat_bot_copy.GetImageHandle()->IsOk());
    CHECK(chat_bot.GetImageHandle() != chat_bot_copy.GetImageHandle());
  }
  SECTION("Copy Assignment") {
    ChatBot chat_bot(kImageFile);
    ChatBot chat_bot_copy;
    chat_bot_copy = chat_bot;
    CHECK(chat_bot.GetImageHandle()->IsOk());
    CHECK(chat_bot_copy.GetImageHandle()->IsOk());
    CHECK(chat_bot.GetImageHandle() != chat_bot_copy.GetImageHandle());
  }
  SECTION("Move Constructor") {
    ChatBot chat_bot(kImageFile);
    auto image = chat_bot.GetImageHandle();
    ChatBot chat_bot_copy(std::move(chat_bot));
    CHECK(chat_bot.GetImageHandle() == nullptr);
    CHECK(chat_bot_copy.GetImageHandle() == image);
  }
  SECTION("Move Assignment") {
    ChatBot chat_bot(kImageFile);
    auto image = chat_bot.GetImageHandle();
    ChatBot chat_bot_copy;
    chat_bot_copy = std::move(chat_bot);
    CHECK(chat_bot.GetImageHandle() == nullptr);
    CHECK(chat_bot_copy.GetImageHandle() == image);
  }
}