cmake_minimum_required(VERSION 3.9)
project(ov5)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov5 main.cpp utilities.cpp utilities.h Card.cpp Card.h CardDeck.cpp CardDeck.h Blackjack.cpp Blackjack.h)