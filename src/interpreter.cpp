#include "interpreter.h"

#include <regex>
#include <sstream>

#include "ascii_converter.h"
#include "util.h"

Result evaluate(std::string code, Memory memory, int start_index) {
    using namespace std;

    stringstream result_stream;

    for (unsigned int i = start_index; i < code.length(); i ++) {
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
            result_stream << (char) emory.get_current_value();
        } else if (symbol == ',') {
            int input = 0;

            while (true) {
                cout << endl << "Input> ";

                string word;
                cin >> word;

                if (is_int(word)) {
                    input = to_int(word);
                    break;
                } else {
                    cout << "Please enter a number." << endl;
                }
            }

            memory.set_value(input);
        } else if (symbol == '[') {
            int loop_end_index = search_loop_end(code, i);
            if (loop_end_index == -1) {
                cout << "The end of the loop couldn't be identified." << endl;
                exit(1);
            }

            string loop_code = code.substr(i + 1, loop_end_index - (i + 1));

            while (memory.get_current_value() != 0) {
                Result result = evaluate(loop_code, memory, 0);
                result_stream << result.output;
                memory = result.memory;
            }

            Result result = evaluate(code, memory, loop_end_index);
            result_stream << result.output;
            memory = result.memory;

            break;
        }
    }

    return Result(result_stream.str(), memory);
}
