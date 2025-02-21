from graphviz import Digraph

def create_nivel_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Nivel')
    dot.node('A', 'Inicio')
    dot.node('B', 'Inicializar nivel_anterior, resultado = 1, nivel = 1')
    dot.node('C', 'Recorrer nivel_anterior')
    dot.node('D', 'resultado *= 2')
    dot.node('E', 'resultado > i + 1')
    dot.node('F1', 'nivel = nivel_anterior')
    dot.node('F2', 'nivel = nivel_anterior + 1')
    dot.node('G', 'Retornar nivel')

    dot.edge('A', 'B')
    dot.edge('B', 'C')
    dot.edge('C', 'D')
    dot.edge('D', 'E')
    dot.edge('E', 'F1', label='Sí')
    dot.edge('E', 'F2', label='No')
    dot.edge('F1', 'G')
    dot.edge('F2', 'G')

    dot.render('nivel_flowchart', format='png')

if __name__ == "__main__":
    create_nivel_flowchart()

