#include <unordered_map>

class Memory {
    public:
        int pointer = 0;
        std::unordered_map<int, int> entries = {};

        void increment();
        void decrement();
        void increment_value();
        void decrement_value();
        void set_value(int new_value);
        bool has_value();
        int  get_current_value();
};
