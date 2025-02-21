from graphviz import Digraph

def create_buscar_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Buscar')
    dot.node('A', 'Inicio')
    dot.node('B', 'Leer val')
    dot.node('C', 'Recorrer arbol')
    dot.node('D1', 'arbol[i].izquierda == val or arbol[i].derecha == val')
    dot.node('E1', 'Mostrar mensaje encontrado')
    dot.node('F1', 'Leer respuesta')
    dot.node('G1', 'respues == 1')
    dot.node('H1', 'posicion = i')
    dot.node('G2', 'respues == 2')
    dot.node('H2', 'Llamar función transver')
    dot.node('I', 'Mostrar mensaje no encontrado')

    dot.edge('A', 'B')
    dot.edge('B', 'C')
    dot.edge('C', 'D1')
    dot.edge('D1', 'E1', label='Sí')
    dot.edge('E1', 'F1')
    dot.edge('F1', 'G1', label='1')
    dot.edge('F1', 'G2', label='2')
    dot.edge('G1', 'H1')
    dot.edge('G2', 'H2')
    dot.edge('H1', 'I')
    dot.edge('H2', 'I')
    dot.edge('D1', 'C', label='No')
    dot.edge('C', 'I', label='Fin búsqueda')

    dot.render('buscar_flowchart', format='png')

if __name__ == "__main__":
    create_buscar_flowchart()

