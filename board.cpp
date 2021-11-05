#include "board.h"

Board::Board(int width, int height, int mine_count) {
    this->width = width;
    this->height = height;
    this->mine_count = mine_count;
    this->cells = new uint8_t[width * height];
}

Board::Board(uint8_t* cells) {
    this->cells = cells;
}

void Board::generate(int guess_x, int guess_y) {
    set_revealed(guess_x, guess_y, true);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr_x(0, width); // define the range
    std::uniform_int_distribution<> distr_y(0, height); // define the range

    int x, y;
    for (int i = 0; i < mine_count; i++) {
        while (true) {
            x = distr_x(gen);
            y = distr_y(gen);
            uint8_t &cell = at(x, y);

            if (!is_mine(cell) && !is_revealed(cell)) {
                set_mine(x, y, true);
            }
        }
    }
}

uint8_t* Board::get_neighbors(int x, int y) {
   int count = (x == width - 1 || x == 0 || y == height - 1 || y == 0) ? 5 : 8;
   uint8_t neighbors[count];
   int i = 0;

   if (x != 0) {
       neighbors[i] = at(x - 1, y);
       i++;
   }
   if (y != 0) {
       neighbors[i] = at(x, y - 1);
       i++;
   }
   if (x != width - 1) {
       neighbors[i] = at(x + 1, y);
       i++;
   }
   if (y != height - 1) {
       neighbors[i] = at(x, y + 1);
       i++;
   }
   if (x != 0 && y != 0) {
       neighbors[i] = at(x - 1, y - 1);
       i++;
   }
   if (x != 0 && y != height - 1) {
       neighbors[i] = at(x - 1, y + 1);
       i++;
   }
   if (x != width - 1 && y != 0) {
       neighbors[i] = at(x + 1, y - 1);
       i++;
   }
   if (x != width - 1 && y != height - 1) {
       neighbors[i] = at(x + 1, y + 1);
       i++;
   }

   return neighbors;
}

uint8_t* Board::set_mine(int x, int y, bool is_mine) {
    uint8_t* neighbors[3];

    for(const uint8_t &cell : neighbors) {
        
    }
}


void Board::solve() {

}

uint8_t& Board::at(int x, int y) {
    return cells[y * width + x];
}

void Board::print() {

}