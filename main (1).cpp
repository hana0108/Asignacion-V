#include <iostream>
#include <vector>
using namespace std;

// Clase Participant
class Participant {
public:
    string name;
    int score;

    Participant(string n, int s) {
        name = n;
        score = s;
    }
};

// Función para buscar participante por nombre
void searchParticipant(vector<Participant>& participants, string nameToFind) {

    for (int i = 0; i < participants.size(); i++) {

        if (participants[i].name == nameToFind) {

            cout << "\n=== PARTICIPANTE ENCONTRADO ===" << endl;
            cout << "Nombre: " << participants[i].name << endl;
            cout << "Puntuacion: " << participants[i].score << endl;
            return;
        }
    }

    cout << "\nParticipante no encontrado." << endl;
}

int main() {

    // Lista de participantes
    vector<Participant> participants;

    participants.push_back(Participant("Daniel", 95));
    participants.push_back(Participant("Genesis", 88));
    participants.push_back(Participant("Yanibel", 92));

    string nombre;

    cout << "Participantes registrados:" << endl;
    cout << "- Daniel" << endl;
    cout << "- Genesis" << endl;
    cout << "- Yanibel" << endl;

    cout << "\nIngrese el nombre a buscar: ";
    cin >> nombre;

    searchParticipant(participants, nombre);

    return 0;
}