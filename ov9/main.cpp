// SFML-2.4.2-windows-gcc-6.1.0-mingw-64-bit

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Minesweeper.h"


const sf::Color open_fill_color = sf::Color::White, closed_fill_color(192, 192, 192);
const sf::Color number_colors[9] = {
        sf::Color::White,
        sf::Color::Blue,
        sf::Color(0, 128, 0),
        sf::Color::Red,
        sf::Color(0, 0, 128),
        sf::Color(128, 0, 0),
        sf::Color(0, 128, 128),
        sf::Color::Black,
        sf::Color(128, 128, 128)
};
const sf::Color mine_color = sf::Color::Red;
const sf::Color flag_color = sf::Color::Black;
const sf::Color info_color = sf::Color::White;

const int tile_size = 32;
const int border_size = 2;

int main() {
    srand(time(nullptr));
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")){
        cout << "Did not fine the file 'sansation.ttf'" << endl;
        exit(0);
    }
    int height, width, mines, answere;
    cout << "Welcome to Minesweeper!" << endl;
    cout << "Right click on a tile to open it and left click to mark a flag." << endl;
    cout << "Press ESC or Q to exit, or the SPACEBAR to restart" << endl;
    cout << "Choose difficulty:" << endl;
    cout << "                   Height  Width   Mines" << endl;
    cout << "(1) Beginner       9       9       10   " << endl;
    cout << "(2) Intermediate   16      16      40   " << endl;
    cout << "(3) Expert         16      30      99   " << endl;
    cout << "(4) Custome                             " << endl;
    for(;;){
        cin >> answere;
        if (answere == 1){
            height=9, width=9, mines=10;
            break;
        } else if (answere == 2){
            height=16, width=16, mines=40;
            break;
        } else if (answere == 3){
            height=16, width=30, mines=99;
            break;
        } else if (answere == 4) {
            for(;;) {
                cout << "Write the height (min 4), width (min 4) and number of mines (max height*width-1): ";
                cin >> height >> width >> mines;
                if (height >= 4 && width >= 4 && mines < height * width) {
                    break;
                } else {
                    cout << "Incorrect values! Try again!" << endl;
                }
            }
            break;
        } else{
            cout << "Incorrect answere! Try again!" << endl;
        }
    }
    Minesweeper* game = new Minesweeper(width, height, mines);
    sf::RenderWindow window(sf::VideoMode(width * tile_size, (height+3) * tile_size), "Minesweeper", sf::Style::Close);
    window.setFramerateLimit(60);
    //game->solveGame();
    clock_t start;
    clock_t time = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Escape:
                        case sf::Keyboard::Q:
                            window.close();
                            break;
                        case sf::Keyboard::Space:
                            delete game;
                            game = new Minesweeper(width, height, mines);
                            start = clock();
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && !game->isGameOver()) {
                        int row = event.mouseButton.y / tile_size;
                        int col = event.mouseButton.x / tile_size;
                        if(row >= height){
                            break;
                        }
                        game->openTile(row, col);
                        if (game->isGameOver()) {
                            if(!game->isGameWon()){
                                cout << "GAME OVER! Press ESC or Q to exit, or the SPACEBAR to restart\n" << endl;
                            }else{
                                cout << "GAME WON! Your time was " << time << " seconds" << endl;
                                cout << "Press ESC or Q to exit, or the SPACEBAR to restart\n" << endl;
                            }
                        }
                    }else if (event.mouseButton.button == sf::Mouse::Right && !game->isGameOver()) {
                        int row = event.mouseButton.y / tile_size;
                        int col = event.mouseButton.x / tile_size;
                        game->setRemoveFlag(row, col);
                    }
                    break;
            }
        }
        window.clear();
        for (int col = 0; col < width; ++col) {
            int row = height+1;
            const int tile_x = col * tile_size, tile_y = row * tile_size;
            sf::RectangleShape tile;
            tile.setSize(sf::Vector2f(tile_size, tile_size));
            tile.setFillColor(info_color);
            tile.setPosition(tile_x , tile_y);
            window.draw(tile);
            if (col == 0 || col == 1 || col == width-1 || col == width-2){
                sf::Text text;
                text.setStyle(sf::Text::Bold);
                text.setCharacterSize(tile_size / 2.0);
                if(col == 1){
                    text.setString(to_string(game->minesLeft()));
                } else if(col == 0){
                    text.setString("M:");
                } else if(col == width-2){
                    text.setString("T:");
                } else{
                    if(game->isGameOver()){
                        if(time <= 999){
                            text.setString(to_string(time));
                        }else{
                            text.setString(to_string(999));
                        }
                    }else {
                        time = (clock()-start)/1000;
                        if(time <= 999){
                            text.setString(to_string(int(time)));
                        }else{
                            text.setString(to_string(999));
                        }
                    }
                }
                text.setColor(mine_color);
                text.setFont(font);
                sf::FloatRect text_rect = text.getLocalBounds();
                text.setOrigin(text_rect.left + text_rect.width  / 2.0, text_rect.top  + text_rect.height / 2.0);
                text.setPosition(tile_x + tile_size / 2.0, tile_y + tile_size / 2.0);
                window.draw(text);
            }
        }
        for(int row = 0; row < height; ++row) {
            for(int col = 0; col < width; ++col) {
                const int tile_x = col * tile_size, tile_y = row * tile_size;
                sf::RectangleShape tile;
                tile.setSize(sf::Vector2f(tile_size - border_size, tile_size - border_size));
                tile.setFillColor(game->isTileOpen(row, col) ? open_fill_color : closed_fill_color);
                tile.setPosition(tile_x + border_size / 2.0, tile_y + border_size / 2.0);
                window.draw(tile);
                if (game->isTileOpen(row, col)
                    || game->isTileFlag(row, col)
                    || (game->isGameOver() && game->isTileMine(row, col))) {
                    sf::Text text;
                    text.setStyle(sf::Text::Bold);
                    text.setCharacterSize(tile_size / 2.0);
                    if (game->isTileMine(row, col) && !game->isTileFlag(row, col) ) {
                        text.setString("X");
                        text.setColor(mine_color);
                    }else if(game->isTileFlag(row, col)){
                        text.setString("F");
                        text.setColor(flag_color);
                    } else {
                        int num_adjacent_mines = game->numAdjacentMines(row, col);
                        if(num_adjacent_mines == 0) continue;
                        text.setString(to_string(num_adjacent_mines));
                        text.setColor(number_colors[num_adjacent_mines]);
                    }
                    text.setFont(font);
                    sf::FloatRect text_rect = text.getLocalBounds();
                    text.setOrigin(text_rect.left + text_rect.width  / 2.0, text_rect.top  + text_rect.height / 2.0);
                    text.setPosition(tile_x + tile_size / 2.0, tile_y + tile_size / 2.0);
                    window.draw(text);
                }
            }
        }
        window.display();
    }
    delete game;
    return 0;
}
