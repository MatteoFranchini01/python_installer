#include <iostream>
#include <string>

using namespace std;

string tipo_sistema_operativo () {
    string SO;
    #if defined(__linux__) // Or #if __linux__
        SO = "Linux";
        std::cout << "Hello, GNU/Linux!" << '\n';
    #elif __APPLE__
        SO = "macOS";
        std::cout << "Hello, macOS!" << '\n';
    #elif _WIN32
        SO = "Windows";
        std::cout << "Hello, Windows!" << '\n';
                    #else
                      std::cout << "Hello, Other!" << '\n';
    #endif
}

int main() {
    string SO;
    string scelta; bool scelta_effettuata = false;
    int system_return_value;
    system_return_value = system("python3 --version"); // Esegue il comando "python --version" nel terminale
    if (system_return_value == 0) {
        cout << "Python è presente sul computer!" << endl;
    } else {
        while (scelta_effettuata == false) {
            cout << "Python non è presente sul computer." << endl;
            cout << "Per l'esecuzione di questo programma è necesaria l'installazione di Python, vuoi installarlo ora? \n "
                       "Premere \"s\" per continuare o \"n\" per annullare" << endl;
            cin >> scelta;
            if (scelta == "S" || scelta == "s") {
                SO = tipo_sistema_operativo();
                if (SO == "Linux") {
                    system_return_value = system("sudo apt-get install python3");
                } else if (SO == "macOS") {
                    system_return_value = system("brew install python3");
                } else if (SO == "Windows") {
                    system_return_value = system("choco install python3");
                }
                scelta_effettuata = true;
            } else if (scelta == "N" || scelta == "n") {
                system_return_value = system("exit");
                scelta_effettuata = true;
            } else {
                cout << "Scelta non corretta!!" << endl;
                continue;
            }
        }
    }
    // Eseguo il file python
    system_return_value = system("python3 prova.py");
    return 0;
}
