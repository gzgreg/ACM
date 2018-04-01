// C++11
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string errorMessage = "";

string interpretBF(const string& commands)
{
    vector<unsigned char> data(1, 0);
    vector<unsigned char>::iterator dataPtr = data.begin();

    string::const_iterator instructionPtr = commands.begin();
    stack<string::const_iterator> instructionStack;

    int iterationCount = 0;
    string result;

    while (instructionPtr != commands.end())
    {
        iterationCount++;
        if (iterationCount > 50000000) {
            errorMessage = "Too many instructions";
            return "";
        }

        switch (*instructionPtr)
        {
        case '<':
        {
            if (dataPtr != data.begin())
                dataPtr--;
            break;
        }
        case '>':
        {
            dataPtr++;
            if (dataPtr == data.end()) {
                if (data.size() < 30000)
                    data.push_back(0);
                dataPtr = data.end()-1;
            }
            break;
        }
        case '+':
        {
            (*dataPtr)++;
            break;
        }
        case '-':
        {
            (*dataPtr)--;
            break;
        }
        case '.':
        {
            result += (unsigned char)(*dataPtr);
            break;
        }
        case ',':
        {
            // we can't do input but have to keep the character due to the language structure
            break;
        }
        case '[':
        {
            instructionStack.push(instructionPtr);

            if (*dataPtr == 0)
            {
                string::const_iterator startInstructionPtr = instructionPtr;
                while (++instructionPtr != commands.end())
                {
                    iterationCount++;
                    if (iterationCount > 50000000)  {
                        errorMessage = "Too many instructions";
                        return "";
                    }

                    if (*instructionPtr == '[')
                        instructionStack.push(instructionPtr);
                    else if (*instructionPtr == ']')
                    {
                        if (instructionStack.empty()) {
                            errorMessage = "Found a ']' that did not have a matching '['!";
                            return "";
                        }

                        string::const_iterator tempInstructionPtr = instructionStack.top();
                        instructionStack.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (instructionStack.empty()) {
                errorMessage = "Found a ']' that did not have a matching '['!";
                return "";
            }

            if (*dataPtr != 0)
                instructionPtr = instructionStack.top();
            else
                instructionStack.pop();

            break;
        }
        default:
            errorMessage = "Invalid character " + (*instructionPtr);
            return "";
        }

        if (instructionPtr == commands.end()) {
            errorMessage = "Invalid program";
            return "";
        }

        instructionPtr++;
    }

    if (!instructionStack.empty()) {
        errorMessage = "Found a '[' that did not have a matching ']'!";
        return "";
    }

    errorMessage = "";
    return result;
}

string convertToBF(const vector<string>& program) {
    string bfcode = "";
    int R = program.size();
    int C = program[0].size();
    // first check that the program is valid
    for (int r = 0; r < R; ++r) {
        if ((int)program[r].size() != C) {
            errorMessage = "Each line of your code must have the same length";
            return "";
        }
        for (int c = 0; c < C; ++c) {
            if (program[r][c] != 'X' && program[r][c] != '.') {
                errorMessage = "Each character of your code must be either 'X' or '.'";
                return "";
            }
        }
    }

    cerr << R << " " << C << endl;

    // now convert the program to BF
    // read off each character in reading order and convert Xs to commands
    for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c) {
        // interpret only X characters
        if (program[r][c] != 'X')
            continue;
        // command is defined by the following neighborhood
        // .2.
        // 1X3
        // in thoroidal topology
        string mask = "";
        mask += program[r][(c-1+C) % C];
        mask += program[(r-1+R) % R][c];
        mask += program[r][(c+1) % C];
        if (mask == "..X") bfcode += '>';
        else
        if (mask == "X..") bfcode += '<';
        else
        if (mask == "XXX") bfcode += '+';
        else
        if (mask == "...") bfcode += '-';
        else
        if (mask == ".X.") bfcode += '.';
        else
        if (mask == "X.X") bfcode += ',';      // will be ignored later
        else
        if (mask == "XX.") bfcode += '[';
        else
        if (mask == ".XX") bfcode += ']';
        else {
            errorMessage = "Unknown neighborhood " + mask;
            return "";
        }
    }
    errorMessage = "";
    return bfcode;
}

int main() {
    // read language program (preserve line breaks)
    vector<string> raw;
    string t;
    while (cin >> t) {
        raw.push_back(t);
        if (raw.size() > 10000) {
            cerr << "Raw program has too many lines" << endl;
            return -1;
        }
    }
    if (raw[0].size() > 10000) {
        cerr << "Raw program has too many columns" << endl;
        return -1;
    }

    // convert to BF code and check that it's valid
    errorMessage = "";
    string bf = convertToBF(raw);
    if (errorMessage != "") {
        cerr << "BF conversion error: " << errorMessage << endl;
        return -1;
    }
    if (bf.length() > 500000) {
        cerr << "BF program too long" << endl;
        return -1;
    }

    cerr << bf << endl;

    // interpret BF code
    string answer = interpretBF(bf);
    if (errorMessage != "") {
        cerr << "BF interpretation error: " << errorMessage << endl;
        return -1;
    }
    cout << answer << endl;
    return 0;
}
