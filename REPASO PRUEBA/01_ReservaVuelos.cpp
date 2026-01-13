#include <iostream>
#include <vector>
using namespace std;

struct Pasajero {
    int id;
    string nombre;
    string asiento; // Ej: "A1", "B3"
};

struct Vuelo {
    int codigo;
    string origen;
    string destino;
    size_t capacidad;
    vector<Pasajero> pasajeros;
};

int buscarVuelo(const vector<Vuelo> &vuelos, int codigo) {
    for (size_t i = 0; i < vuelos.size(); i++) {
        if (vuelos[i].codigo == codigo) return i;
    }
    return -1;
}

void registrarVuelo(vector<Vuelo> &vuelos) {
    Vuelo nuevoV;

    cout << "\n\tNUEVO VUELO\n";
    cout << "CODIGO\n> ";
    cin >> nuevoV.codigo;
    cin.ignore();

    cout << "ORIGEN\n> ";
    getline(cin, nuevoV.origen);

    cout << "DESTINO\n> ";
    getline(cin, nuevoV.destino);

    cout << "CAPACIDAD\n> ";
    cin >> nuevoV.capacidad;

    nuevoV.pasajeros.clear();
    vuelos.push_back(nuevoV);

    cout << "\nVuelo registrado con éxito\n";
}

void registrarPasajero(vector<Vuelo> &vuelos) {
    if (vuelos.empty()) {
        cout << "\nNo hay vuelos registrados\n";
        return;
    }

    int codigo;
    cout << "CODIGO DEL VUELO: ";
    cin >> codigo;

    int posVuelo = buscarVuelo(vuelos, codigo);
    if (posVuelo == -1) {
        cout << "\nVuelo no encontrado\n";
        return;
    }

    if (vuelos[posVuelo].pasajeros.size() >= vuelos[posVuelo].capacidad) {
        cout << "\nCapacidad máxima alcanzada\n";
        return;
    }

    Pasajero nuevoP;
    cout << "\n\tNUEVO PASAJERO\n";
    cout << "ID\n> ";
    cin >> nuevoP.id;
    cin.ignore();

    for (const auto &p : vuelos[posVuelo].pasajeros) {
        if (p.id == nuevoP.id) {
            cout << "\nID ya existe en este vuelo\n";
            return;
        }
    }

    cout << "NOMBRE\n> ";
    getline(cin, nuevoP.nombre);

    cout << "ASIENTO\n> ";
    cin >> nuevoP.asiento;

    vuelos[posVuelo].pasajeros.push_back(nuevoP);
    cout << "\nPasajero registrado con éxito\n";
}

void listarVuelos(const vector<Vuelo> &vuelos) {
    if (vuelos.empty()) {
        cout << "\nNo hay vuelos registrados\n";
        return;
    }

    for (const auto &v : vuelos) {
        cout << "\nVUELO " << v.codigo << " | " << v.origen
             << " -> " << v.destino
             << " | CAPACIDAD: " << v.capacidad
             << " | OCUPADOS: " << v.pasajeros.size();

        if (v.pasajeros.empty()) {
            cout << "\n\tSin pasajeros";
        } else {
            for (const auto &p : v.pasajeros) {
                cout << "\n\tPASAJERO " << p.id
                     << " | " << p.nombre
                     << " | ASIENTO: " << p.asiento;
            }
        }
    }
    cout << endl;
}

void buscarPasajero(const vector<Vuelo> &vuelos) {
    int id;
    cout << "ID DEL PASAJERO: ";
    cin >> id;

    for (const auto &v : vuelos) {
        for (const auto &p : v.pasajeros) {
            if (p.id == id) {
                cout << "\nPasajero encontrado en VUELO "
                     << v.codigo << " (" << v.origen
                     << " -> " << v.destino << ")\n";
                return;
            }
        }
    }
    cout << "\nPasajero no encontrado\n";
}

void eliminarPasajero(vector<Vuelo> &vuelos) {
    int id;
    cout << "ID DEL PASAJERO A ELIMINAR: ";
    cin >> id;

    for (auto &v : vuelos) {
        for (size_t i = 0; i < v.pasajeros.size(); i++) {
            if (v.pasajeros[i].id == id) {
                v.pasajeros.erase(v.pasajeros.begin() + i);
                cout << "\nPasajero eliminado con éxito\n";
                return;
            }
        }
    }
    cout << "\nPasajero no encontrado\n";
}

vector<Vuelo> obtenerVuelosLlenos(const vector<Vuelo> &vuelos) {
    vector<Vuelo> llenos;
    for (const auto &v : vuelos) {
        if (v.pasajeros.size() >= v.capacidad) {
            llenos.push_back(v);
        }
    }
    return llenos;
}

int main() {
    system("chcp 65001 > nul");
    vector<Vuelo> vuelos;
    int opcion;

    do {
        cout << "\n==== MENU ===="
             << "\n1. Registrar vuelo"
             << "\n2. Registrar pasajero"
             << "\n3. Listar vuelos"
             << "\n4. Buscar pasajero"
             << "\n5. Eliminar pasajero"
             << "\n6. Mostrar vuelos llenos"
             << "\n7. Salir\n>>> ";
        cin >> opcion;

        switch (opcion) {
        case 1: registrarVuelo(vuelos); break;
        case 2: registrarPasajero(vuelos); break;
        case 3: listarVuelos(vuelos); break;
        case 4: buscarPasajero(vuelos); break;
        case 5: eliminarPasajero(vuelos); break;
        case 6: {
            vector<Vuelo> llenos = obtenerVuelosLlenos(vuelos);
            if (llenos.empty()) {
                cout << "\nNo hay vuelos llenos\n";
            } else {
                cout << "\nVUELOS LLENOS:";
                for (const auto &v : llenos) {
                    cout << "\nVUELO " << v.codigo
                         << " | " << v.origen << " -> " << v.destino;
                }
            }
            break;
        }
        case 7:
            cout << "\nGRACIAS POR USAR EL SISTEMA\n";
            break;
        default:
            cout << "\nOpción inválida\n";
        }
    } while (opcion != 7);

    return 0;
}
