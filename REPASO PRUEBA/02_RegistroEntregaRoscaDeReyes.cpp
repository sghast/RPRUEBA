#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void subtotalPorEntrega(string entregas[], int n) {
    for (int i=0; i<n; i++) {
        int pos1 = entregas[i].find("//");
        int pos2 = entregas[i].find("//", pos1 + 2);
        int pos3 = entregas[i].find("//", pos2 + 2);
        int pos4 = entregas[i].find("//", pos3 + 2);
        string hora = entregas[i].substr(0, pos1);
        string nombre = entregas[i].substr(pos1 + 2, pos2 - (pos1 + 2));
        string tipoRosca = entregas[i].substr(pos2 + 2, pos3 - (pos2 + 2));
        string cantidad = entregas[i].substr(pos3 + 2, pos4 - (pos3 + 2));
        string precio = entregas[i].substr(pos4 + 2);

        int cant = stoi(cantidad);
        double pre = stod(precio);

        double subtotal = cant * pre;

        cout << hora << " | " <<  setw(7) << nombre << " | " << setw(20) << tipoRosca 
             << " | Subtotal: $" << fixed << setprecision(2) << subtotal << endl;        
    }
}

double totalGeneral(string entregas[], int n) {
    double total = 0;
    for (int i=0; i<n; i++) {
        int pos1 = entregas[i].find("//");
        int pos2 = entregas[i].find("//", pos1 + 2);
        int pos3 = entregas[i].find("//", pos2 + 2);
        int pos4 = entregas[i].find("//", pos3 + 2);
        string cantidad = entregas[i].substr(pos3 + 2, pos4 - (pos3 + 2));
        string precio = entregas[i].substr(pos4 + 2);

        int cant = stoi(cantidad);
        double pre = stod(precio);

        double subtotal = cant * pre;
        total += subtotal;
    }
    return total;
}

void totalPorEncargado(string entregas[], int n) {
    double totalAna = 0, totalLuis = 0, totalPedro = 0;
    for (int i=0; i<n; i++) {
        int pos1 = entregas[i].find("//");
        int pos2 = entregas[i].find("//", pos1 + 2);
        int pos3 = entregas[i].find("//", pos2 + 2);
        int pos4 = entregas[i].find("//", pos3 + 2);
        string nombre = entregas[i].substr(pos1 + 2, pos2 - (pos1 + 2));
        string cantidad = entregas[i].substr(pos3 + 2, pos4 - (pos3 + 2));
        string precio = entregas[i].substr(pos4 + 2);

        int cant = stoi(cantidad);
        double pre = stod(precio);

        double subtotal = cant * pre;

        if (nombre == "Ana") totalAna += subtotal;
        else if (nombre == "Luis") totalLuis += subtotal;
        else if (nombre == "Pedro") totalPedro += subtotal;
    }
    cout << fixed << setprecision(2);
    cout << "\n- Ana: $" << totalAna;
    cout << "\n- Luis: $" << totalLuis;
    cout << "\n- Pedro: $" << totalPedro;
}

string horaMayorMonto(string entregas[], int n) {
    double mayor = 0;
    string horaMax = "00:00";
    for (int i=0; i<n; i++) {
        int pos1 = entregas[i].find("//");
        int pos2 = entregas[i].find("//", pos1 + 2);
        int pos3 = entregas[i].find("//", pos2 + 2);
        int pos4 = entregas[i].find("//", pos3 + 2);
        string hora = entregas[i].substr(0, pos1);
        string nombre = entregas[i].substr(pos1 + 2, pos2 - (pos1 + 2));
        string cantidad = entregas[i].substr(pos3 + 2, pos4 - (pos3 + 2));
        string precio = entregas[i].substr(pos4 + 2);

        int cant = stoi(cantidad);
        double pre = stod(precio);

        double subtotal = cant * pre;

        if (subtotal > mayor) {
            mayor = subtotal;
            horaMax = hora;
        }
    }
    return horaMax;
}

int main() {
    system("chcp 65001 > nul");
    int n = 8;
    string entregas[] = {
        "08:30//Ana//Rosca Tradicional//3//8.50",
        "08:50//Luis//Rosca Chocolate//2//10.00",
        "09:10//Ana//Rosca Rellena//1//12.75",
        "09:30//Pedro//Rosca Tradicional//4//8.50",
        "09:50//Luis//Rosca Mini//6//4.00",
        "10:10//Ana//Rosca Chocolate//2//10.00",
        "10:30//Pedro//Rosca Rellena//1//12.75",
        "10:50//Luis//Rosca Tradicional//3//8.50"
    };
    subtotalPorEntrega(entregas, n);
    cout << "El total general es: $" << totalGeneral(entregas, n);
    totalPorEncargado(entregas, n);
}