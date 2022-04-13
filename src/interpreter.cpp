#include <regex>
#include <sstream>

#include "ascii_converter.h"
#include "interpreter.h"
#include "util.h"

std::tuple<std::string, Memory> evaluate(std::string code, Memory memory) {
    using namespace std;

    stringstream result_stream;

    for (int i = 0; i < code.length(); i ++) {
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
            cout << "Input was requested." << endl;

            bool done = false;
            int input = 0;

            while (!done) {
                cout << endl;
                cout << "Input> ";

                string word;
                cin >> word;

                if (regex_match(word, regex("[+-]?[0-9]{1,}"))) {
                    long num = atol(word.c_str());

                    if (num >= -128 && num <= 127) {
                        input = (int) num;
                        done = true;
                        break;
                    } else {
                        cout << "Please enter a 1 byte number." << endl;
                    }
                } else {
                    cout << "Please enter a 1 byte number." << endl;
                }
            }

            memory.set_value(input);
        } else if (symbol == '[') {
            string code_before_bracket = code.substr(0, index);
            string code_after_bracket = code.substr(index, code.length());

            int loop_end_index = search_loop_end(code_before_bracket, code_after_bracket);
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
