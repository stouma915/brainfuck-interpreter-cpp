#include <regex>
#include <sstream>

#include "ascii_converter.h"
#include "interpreter.h"

std::string evaluate(std::string code, Memory memory) {
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
        }
    }

    return result_stream.str();
}
