from graphviz import Digraph

def create_transver_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Transver')
    dot.node('A', 'Inicio')
    dot.node('B', 'Mientras posicion >= 0')
    dot.node('C', 'trans = arbol[posicion].padre')
    dot.node('D1', 'trans == 0')
    dot.node('E1', 'Imprimir arbol[posicion].izquierda (nodo raíz)')
    dot.node('D2', 'trans % 2 != 0')
    dot.node('E2', 'Imprimir arbol[posicion].izquierda')
    dot.node('E3', 'Imprimir arbol[posicion].derecha')
    dot.node('F', 'posicion = trans - 1')
    dot.node('G', 'Fin')

    dot.edge('A', 'B')
    dot.edge('B', 'C')
    dot.edge('C', 'D1')
    dot.edge('D1', 'E1', label='Sí')
    dot.edge('D1', 'D2', label='No')
    dot.edge('D2', 'E2', label='Sí')
    dot.edge('D2', 'E3', label='No')
    dot.edge('E1', 'F')
    dot.edge('E2', 'F')
    dot.edge('E3', 'F')
    dot.edge('F', 'B')
    dot.edge('B', 'G', label='No más nodos')

    dot.render('transver_flowchart', format='png')

if __name__ == "__main__":
    create_transver_flowchart()

