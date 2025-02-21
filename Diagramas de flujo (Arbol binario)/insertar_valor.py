from graphviz import Digraph

def create_insertar_valor_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Insertar Valor')
    dot.node('A', 'Inicio')
    dot.node('B', 'Leer respuesta')
    dot.node('C1', 'indice == 0')
    dot.node('D1', 'Set arbol[indice].arbol, izquierda, nivel')
    dot.node('C2', 'indice % 2 != 0')
    dot.node('D2', 'Set arbol[indice].izquierda')
    dot.node('D3', 'Set arbol[indice].derecha')
    dot.node('E', 'Set arbol[indice].arbol, nivel, padre')
    dot.node('F', 'Incrementar indice')
    dot.node('G', 'Fin')

    dot.edge('A', 'B')
    dot.edge('B', 'C1')
    dot.edge('C1', 'D1', label='Sí')
    dot.edge('D1', 'E')
    dot.edge('C1', 'C2', label='No')
    dot.edge('C2', 'D2', label='Sí')
    dot.edge('C2', 'D3', label='No')
    dot.edge('D2', 'E')
    dot.edge('D3', 'E')
    dot.edge('E', 'F')
    dot.edge('F', 'G')

    dot.render('insertar_valor_flowchart', format='png')

if __name__ == "__main__":
    create_insertar_valor_flowchart()

