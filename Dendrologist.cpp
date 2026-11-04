/**
 * A testbed for an augmented implementation of an AVL tree
 * @author William Duncan, Elaina Andrews
 * @see AVLTree.h
 * <pre>
 * Date: 10/28/2026
 * Course: CSC 3102 
 * Programming Project # 2
 * Instructor: Dr. Duncan 
 * </pre>
 */

#include <iostream>
#include <cstdlib>  
#include <stdexcept>
#include <iomanip>
#include <fstream> 
#include <algorithm>
#include <vector>
#include "AVLTree.cpp"
#include <sstream>


using namespace std;

//1 normal lexicographical order
int increasingLex(string a, string b) {
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

//-1 reverse lexicographical order
int decreasingLex(string a, string b) {
     if(a > b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}
//2 increasing length
int increasingLength(string a, string b) {
     if (a.length() < b.length()) {
        return -1;
    } else if (a.length() == b.length()) {
        return 0;
    } else {
        return 1;
    }
}

//-2 decreasing length
int decreasingLength(string a, string b) {
    if(a.length() > b.length()) {
     return -1;
    } else if (a.length() == b.length()) {
        return 0;
    } else {
        return 1;   
    }
}

//3 checks if lengths are not different, if they are not returns lexicographical order
int increasingLengthLex(string a, string b) {
    if (a.length() != b.length()) {
        if (a.length() < b.length()) {
        return -1;
        } else {
        return 1;
    }
}
return increasingLex(a, b);
}

//0 checks if thengths are not different, if they are not returns reverse lexicgraphical order
int increasingLengthReverseLex (string a, string b) {
    if (a.length() != b.length()) {
        if (a.length() < b.length()) {
        return -1;
        } else {
        return 1;
    }
    }
    return decreasingLex(a, b);
}

//-3 checks if lengths are not different, if they are not returns reverse lexicogeaphical order
int decreasingLengthLex(string a, string b) {
    if (a.length() != b.length()) {
        if(a.length() > b.length()) {
     return -1;
    } else{
        return 1;
    }   
    }
    return decreasingLex(a, b);
}
// traverse accepting string from avl tree
void printWord(const string& word) {
    cout << word << "\n";
}



int main(int argc, char** argv) 
{
    string usage = "Dendrologist <order-code> <command-file>\n";
    usage += "  <order-code>:\n";
    usage += "  0 ordered by increasing string length, primary key, and reverse lexicographical order, secondary key\n";
    usage += "  -1 for reverse lexicographical order\n";
    usage += "  1 for lexicographical order\n";
    usage += "  -2 ordered by decreasing string\n";
    usage += "  2 ordered by increasing string\n";
    usage += "  -3 ordered by decreasing string length, primary key, and reverse lexicographical order, secondary key\n";
    usage += "  3 ordered by increasing string length, primary key, and lexicographical order, secondary key\n"; 
    try {
        if (argc != 3)
        {
            cout<<usage<<endl;
            throw invalid_argument("There should be 3 command line arguments.");
        }
    
        //Complete the implementation of this function
        //won't compile unless orderCode is inputed. Meaning strings and mixed variables will not pass.
        size_t pos = 0;
        int orderCode;

        try {
            orderCode = stoi(argv[1], &pos);
        } catch (const invalid_argument&) {
            cout<<usage<<endl;
            throw invalid_argument("Invalid order code.");

        } catch (const out_of_range&) {
            cout<<usage<<endl;
            throw invalid_argument("Invalid order code.");
        }

        if (pos != string(argv[1]).length()) {
            cout<<usage<<endl;
            throw invalid_argument("Invalid order code.");
        }

        int (*compare)(string, string);

        if (orderCode == -1) {
        compare = decreasingLex;
        } else if (orderCode == 1) {
        compare = increasingLex;
        } else if (orderCode == -2) {
        compare = decreasingLength;
        } else if (orderCode == 2) {
        compare = increasingLength;
        } else if (orderCode == -3) {
        compare = decreasingLengthLex;
        } else if (orderCode == 0) {
        compare = increasingLengthReverseLex;
        } else if (orderCode == 3) {
        compare = increasingLengthLex;
        }

        if (orderCode < -3 || orderCode > 3) {
            cout<<usage<<endl;
            throw invalid_argument("Order code must be between -3 and 3."); //can't run the program if not in bounds
        }

        ifstream commandFile(argv[2]);

        if (!commandFile.is_open()) {
            cout<<usage<<endl;
            throw invalid_argument("This file could not be opened."); //checking to make sure nonexistent files cannot be opened or created
        }

        AVLTree<string> tree(compare);
        string line;

        while(getline(commandFile, line)) {
        istringstream iss(line); //splits line into individual words

        string command;

        iss >> command; //extracting first word and storing it in command

        if(command != "insert" &&
            command != "delete" &&
            command != "traverse" &&
            command != "paths" &&
            command != "stats") {
                throw invalid_argument("Parsing error: invalid command");
            }

        // error for trying to insert 0 words
        string word;

        if (command == "insert" || command == "delete") {
            if (!(iss >> word)) {
                throw invalid_argument("Parsing error: missing word");
            }
        }

        // error for trying to use more than one word at a time
        string extra;

        if (iss >> extra) {
            throw invalid_argument("Parsing error: extra argument");
        }

        if (command == "insert") {
            tree.insert(word); // inserts word into avl tree
            cout << "Inserted: " << word << endl;
        } else if (command == "delete") {
             tree.remove(word);
             cout << "Deleted: " << word << endl;
        } else if (command == "stats") {
            cout << "Stats: size = " << tree.size() << ", height = " << tree.height() 
            << ", #full-nodes = " << tree.fullCount() << ", fibonacci? = " << boolalpha << tree.isFibonacci() 
            << endl;
        } else if (command == "traverse") {
            cout << "In-Order Traversal:" << endl;
            tree.traverse(printWord);
        } else if (command == "paths") {
            vector<string> paths = tree.genPaths();

            cout << "#Root-to-Leaf Paths: " << paths.size() << endl;

            for (const string& path : paths) {
                cout << path << endl;
            }
        } else {
            // signals an error occured and described the problem
            throw invalid_argument("Parsing error: invalid command");
        }
        }
       
        return 0;
        }
        catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
}

