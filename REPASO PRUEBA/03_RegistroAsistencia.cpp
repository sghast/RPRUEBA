#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void procesarRegistros(string asistencias[], int n) {
    for (int i=0; i<n; i++) {
        int pos1 = asistencias[i].find("|");
        int pos2 = asistencias[i].find("|", pos1 + 1);
        int pos3 = asistencias[i].find("|", pos2 + 1);

        string hora = asistencias[i].substr(0, pos1);
        string nombre = asistencias[i].substr(pos1 + 1, pos2 - (pos1 + 1));
        string materia = asistencias[i].substr(pos2 + 1, pos3 - (pos2 + 1));
        string asistencia = asistencias[i].substr(pos3 + 1);

        int nAsistencias = stoi(asistencia);

        cout << hora << " | " << setw(8) << nombre << " | " 
             << setw(17) << materia << " | " << nAsistencias << endl;
    }
}

int sumaAsistencias(string asistencias[], int n) {
    int asistenciasT = 0;
    for (int i=0; i<n; i++) {
        int pos1 = asistencias[i].find("|");
        int pos2 = asistencias[i].find("|", pos1 + 1);
        int pos3 = asistencias[i].find("|", pos2 + 1);

        string asistencia = asistencias[i].substr(pos3 + 1);

        int asistencias = stoi(asistencia);
        asistenciasT += asistencias;
    }
    return asistenciasT;
}

void asistenciaPorMateria(string asistencias[], int n) {
    int aMAT = 0, aPRO = 0, aFIS = 0;
    for (int i=0; i<n; i++) {
        int pos1 = asistencias[i].find("|");
        int pos2 = asistencias[i].find("|", pos1 + 1);
        int pos3 = asistencias[i].find("|", pos2 + 1);

        string materia = asistencias[i].substr(pos2 + 1, pos3 - (pos2 + 1));
        string asistencia = asistencias[i].substr(pos3 + 1);

        int asistencias = stoi(asistencia);

        if (materia == "Programación") aPRO += asistencias;
        else if (materia == "Matemáticas") aMAT += asistencias;
        else if ( materia == "Física") aFIS += asistencias;
    }
    cout << "\nProgramación: " << aPRO;
    cout << "\nMatemáticas: " << aMAT;
    cout << "\nFísica: " << aFIS;
}

int main() {
    system("chcp 65001 < nul");
    int n = 5;
    string asistencias[] = {
        "07:00|Carlos|Programación|1",
        "07:45|Maria|Matemáticas|1",
        "08:30|Luis|Programación|1",
        "09:15|Ana|Física|1",
        "10:00|Pedro|Matemáticas|1"
    };
    procesarRegistros(asistencias, n);
    cout << "Total de asistencias: " << sumaAsistencias(asistencias, n);
    asistenciaPorMateria(asistencias, n);
}