#include <regex>
#include <sstream>

#include "ascii_converter.h"
#include "interpreter.h"
#include "util.h"

std::tuple<std::string, Memory> evaluate(std::string code, Memory memory) {
    using namespace std;

    stringstream result_stream;

    for (unsigned int i = 0; i < code.length(); i ++) {
        int index = i;
        char symbol = code[i];

        if (symbol == '+') {
            memory.increment_value();
        } else if (symbol == '-') {
            memory.decrement_value();
        } else if (symbol == '>') {
            memory.increment();
        } else if (symbol == '<') {
            memory.decrement();
        } else if (symbol == '.') {
            result_stream << convert_ascii(memory.get_current_value());
        } else if (symbol == ',') {
            int input = 0;

            while (true) {
                cout << endl << "Input> ";

                string word;
                cin >> word;

                if (is_single_bit_int(word)) {
                    input = to_single_bit_int(word);
                    break;
                } else {
                    cout << "Please enter a 1 byte number." << endl;
                }
            }

            memory.set_value(input);
        } else if (symbol == '[') {
            int loop_end_index = search_loop_end(code, index);
            if (loop_end_index == -1) {
                cout << "The end of the loop couldn't be identified." << endl;
                exit(1);
            }

            string loop_code = code.substr(index + 1, loop_end_index - (index + 1));
            string after_loop = code.substr(loop_end_index, code.length());

            while (memory.get_current_value() != 0) {
                auto [result, mem] = evaluate(loop_code, memory);
                result_stream << result;
                memory = mem;
            }

            auto [result, mem] = evaluate(after_loop, memory);
            result_stream << result;
            memory = mem;

            break;
        }
    }

    return { result_stream.str(), memory };
}
