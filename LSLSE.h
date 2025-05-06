#ifndef LSLSE_H
#define LSLSE_H

#include <iostream>

template<class T>
class LSLSE;

template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {}

    // públicos
    T getData() const { return data; }
    node<T>* getSig() const { return sig; }

    friend class LSLSE<T>;
};

template<class T>
class LSLSE {
private:
    node<T>* lista;
public:
    LSLSE() : lista(nullptr) {}
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;
};

template<class T>
bool LSLSE<T>::vacia() const {
    return lista == nullptr;
}

template<class T>
node<T>* LSLSE<T>::primero() const {
    return lista;
}

template<class T>
node<T>* LSLSE<T>::ultimo() const {
    if (vacia()) return nullptr;
    node<T>* aux = lista;
    while (aux->sig != nullptr)
        aux = aux->sig;
    return aux;
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos) const {
    if (vacia() || pos == nullptr) return nullptr;
    node<T>* aux = lista;
    while (aux != nullptr && aux->sig != pos)
        aux = aux->sig;
    return aux;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem) {
    node<T>* nuevo = new node<T>;
    nuevo->data = elem;
    if (pos == nullptr) {
        nuevo->sig = lista;
        lista = nuevo;
    } else {
        nuevo->sig = pos->sig;
        pos->sig = nuevo;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos) {
    if (vacia() || pos == nullptr)
        return false;
    if (pos == lista) {
        lista = lista->sig;
    } else {
        anterior(pos)->sig = pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        std::cout << aux->getData() << " -> ";
        aux = aux->getSig();
    }
    std::cout << "NULL\n";
}

#endif

