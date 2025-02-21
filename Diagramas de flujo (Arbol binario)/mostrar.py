from graphviz import Digraph

def create_mostrar_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Mostrar')
    dot.node('A', 'Inicio')
    dot.node('B', 'Recorrer los primeros 9 elementos del arbol')
    dot.node('C1', 'arbol[i].arbol == 1')
    dot.node('D1', 'Imprimir arbol[i].izquierda')
    dot.node('C2', 'i % 2 == 0')
    dot.node('D2', 'Imprimir arbol[i].derecha')
    dot.node('D3', 'Imprimir arbol[i].izquierda')
    dot.node('E', 'Fin')

    dot.edge('A', 'B')
    dot.edge('B', 'C1')
    dot.edge('C1', 'D1', label='Sí')
    dot.edge('C1', 'C2', label='No')
    dot.edge('C2', 'D2', label='Sí')
    dot.edge('C2', 'D3', label='No')
    dot.edge('D1', 'E')
    dot.edge('D2', 'E')
    dot.edge('D3', 'E')

    dot.render('mostrar_flowchart', format='png')

if __name__ == "__main__":
    create_mostrar_flowchart()

