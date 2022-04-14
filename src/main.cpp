#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "interpreter.h"
#include "util.h"

#define VERSION "1.0.0"

void show_usage(std::string file_name) {
    std::cout << "Brainf**k Interpreter " << VERSION << "\n"
                 "\n"
                 "Usage:\n"
                 "    " << file_name << " [FLAGS] [SOURCE]\n"
                 "\n"
                 "Flags:\n"
                 "    -h, --help    Prints help information.\n"
                 "\n"
                 "Args:\n"
                 "    <SOURCE> Brainfuck source file.\n";
}

int main(int argc, char* argv[]) {
    using namespace std;

    if (argc < 2) {
        show_usage(argv[0]);

        return 1;
    }

    string source_file_name;

    for (int i = 1; i < argc; i ++) {
        string arg = argv[i];

        if (starts_with(arg, "-")) {
            if (arg == "-h") {
                show_usage(argv[0]);

                return 0;
            } else if (arg == "--help") {
                show_usage(argv[0]);

                return 0;
            } else {
                cout << "Found argument '" << arg << "' which wasn't expected, or isn't valid in this context.\n"
                        "\n"
                        "Usage:\n"
                        "    " << argv[0] << " [FLAGS] [SOURCE]\n"
                        "\n"
                        "For more information try --help\n";

                return 1;
            }
        } else {
            source_file_name = arg;
        }
    }

    ifstream source_file;

    source_file.open(source_file_name, ios::in);
    if (source_file.fail()) {
        cout << "Failed to open '" << source_file_name << "'." << endl;

        return 1;
    }

    filesystem::path source_file_path = filesystem::path(source_file_name);
    if (filesystem::is_directory(source_file_path)) {
        cout << "'" << source_file_name << "' is a directory." << endl;

        return 1;
    }

    stringstream source_stream;
    source_stream << source_file.rdbuf();

    source_file.close();

    string source = source_stream.str();

    Memory memory;
    auto [result, _] = evaluate(source, memory);
    cout << result << endl;
}
