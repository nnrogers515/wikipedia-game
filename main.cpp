#include "mainHelper.hpp"

int main(int argc, char *argv[]) {

    bool successful = true;

    // Defaults
    if (argc <= 3) {      
        defaultExecution(argc, argv);
    } else { // Complex Arguments
        // Parsing Arguments and Converting to Lowercase for the Command for Comparison
        std::vector<std::string> arguments = argsToStrings(argc, argv);
        std::transform(arguments[1].begin(), arguments[1].end(), arguments[1].begin(), [](char c){ return std::tolower(c); });

        // Attempts to Read Passed in File Arguments
        std::ifstream file(arguments[2]);
        if (!file.is_open() || !file.good()) {
            std::cout << "Invalid File or Invalid File Path. Please ensure the file is reachable and has the correct path. Ending Execution." << std::endl;
            return 0;
        }
        
        // Builds Graph and determines if it is weighted or not        
        bool weighted = argc >= 6 && arguments[1] == "dijkstras";
        Graph inputTsv(file, weighted);

        // Algorithm Helper Functions
        if (arguments[1] == "pagerank") {
            successful = pageRankExecution(arguments, argc, inputTsv);
        } else if (arguments[1] == "bfs") {
            successful = BFSExecution(arguments, inputTsv);
        } else if (arguments[1] == "dijkstras") {
            if (arguments[3] == arguments[4]) {
                std::cout << "\nSorry, it appears as though the Start and End points are the same. The path in this case is empty.";
                std::cout << "\nPlease Pick Another Starting and Ending point and try again!\n";
                return 0;
            }
            int temp = dijkstraExecution(arguments, argc, inputTsv);
            if (temp == 2) return 0;
            successful = temp;
        } else {
            // Arguments Didn't Match Any Algorithm Definition
            successful = false;
            std::cout << "Sorry, you have entered an invalid argument sequence! Please look at \'How to Build\' section on Github to learn more!\n";
        }
    }

    if (successful)
        std::cout << "\nSuccess: Please Examine the Contents of the Outputs Folder in your Directory to find your Results!\n";
    else
        std::cout << "\nFailure: Please try again after adjusting your arguments!\n";

    std::cout << "Ending Execution\n\n";
    return 0;
}

