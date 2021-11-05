#include <cstdint>
#include <iostream>
#include <random>

class Board {
    private:
        uint8_t* cells;
        bool is_mine(uint8_t &cell);
        // void set_mine(uint8_t &cell, bool is_mine);
        void set_mine(int x, int y, bool is_mine);
        void set_adj_mines(uint8_t &cell, int adj_mines);
        void set_adj_mines(int x, int y, int adj_mines);

    public:
        int width, height, mine_count;
        Board(int width, int height, int mine_count);
        Board(uint8_t cells[]);
        uint8_t& at(int x, int y);
        uint8_t* get_neighbors(int x, int y);
        bool reveal(int x, int y);
        void get_adj_mines(uint8_t &cell);
        bool is_solved(uint8_t &cell);
        void set_solved(int x, int y, bool is_solved);
        void set_solved(uint8_t &cell, bool is_solved);
        bool is_flagged(uint8_t &cell);
        void set_flagged(int x, int y, bool is_solved);
        void set_flagged(uint8_t &cell, bool is_flagged);
        bool is_revealed(uint8_t &cell);
        void set_revealed(int x, int y, bool is_revealed);
        void set_revealed(uint8_t &cell, bool is_revealed);
        void generate(int guess_x, int guess_y);
        void solve();
        void print();
}