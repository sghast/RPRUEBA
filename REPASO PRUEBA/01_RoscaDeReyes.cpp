#include <iostream>
using namespace std;

struct Rosca {
    int fila;
    int columna;
    bool entregada;
    string cliente;
};

void inicializarMesa(Rosca mesa[][6], int filas, int columnas) {
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            mesa[i][j].fila = i;
            mesa[i][j].columna = j;
            mesa[i][j].entregada = false;
            mesa[i][j].cliente = "";
        }
    }
}

void registrarRosca(Rosca mesa[][6]) {
    int fila, columna;
    string nombre;
    cout << "\nNUEVA ROSCA\n";
    do {
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;

        if (fila < 0 || fila > 2 || columna < 0 || columna > 6) {
            cout << "Fuera de rango\n";
        }
    } while (fila < 0 || fila > 2 || columna < 0 || columna > 6);

    fila--; columna--;
    cin.ignore();

    cout << "Nombre del cliente: ";
    getline(cin, nombre);

    if (mesa[fila][columna].entregada == true) {
        cout << "\nPosición ocupada!";
        return;
    }

    mesa[fila][columna].fila = fila;
    mesa[fila][columna].columna = columna;
    mesa[fila][columna].entregada = true;
    mesa[fila][columna].cliente = nombre;

    cout << "Registrada con éxito!\n";
}

void mostrarMesaDeRoscas(Rosca mesa[][6], int filas, int columnas) {
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << (mesa[i][j].entregada == true ? "[X]" : "[ ]");
        }
        cout << endl;
    }
}

int roscasDisponibles(Rosca mesa[][6], int filas, int columnas) {
    int contador = 0;
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            if (!mesa[i][j].entregada) contador++;
        }
    }
    return contador;
}

int main() {
    system("chcp 65001 > nul");
    const int filas = 2;
    const int columnas = 6;
    int opcion;
    Rosca mesa[filas][columnas];

    while (opcion != 4) {
        cout << "\nROSCAS DE REYES";
        cout << "\n1. Registrar Rosca"
             << "\n2. Mostrar Mesa de Roscas"
             << "\n3. Mostrar Roscas Disponibles"
             << "\n4. SALIR\n> ";
        cin >> opcion;
    
        switch (opcion) {
        case 1: registrarRosca(mesa); break;
        case 2: mostrarMesaDeRoscas(mesa, filas, columnas); break;
        case 3: cout << roscasDisponibles(mesa, filas, columnas); break;
        case 4:
            cout << "\nGracias por ser parte del evento, feliz día de Reyes!";
            break;
        default:
            cout << "\nOpción Inválida\n";
            break;
        }
    }
}