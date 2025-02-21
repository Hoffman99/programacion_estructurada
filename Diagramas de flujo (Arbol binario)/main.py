from graphviz import Digraph

def create_main_flowchart():
    dot = Digraph(comment='Diagrama de Flujo de la Función Main')
    dot.node('A', 'Inicio')
    dot.node('B', 'Inicializar band = 0, indice = 0')
    dot.node('C', 'band == 0')
    dot.node('D', 'Mostrar opciones del menú')
    dot.node('E', 'Leer elección')
    dot.node('F1', 'Insertar un valor')
    dot.node('F2', 'Buscar un valor')
    dot.node('F3', 'Mostrar (los primeros 9)')
    dot.node('F4', 'Cerrar programa')
    dot.node('G', 'Fin')

    dot.edge('A', 'B')
    dot.edge('B', 'C')
    dot.edge('C', 'D', label='Sí')
    dot.edge('D', 'E')
    dot.edge('E', 'F1', label='1')
    dot.edge('E', 'F2', label='2')
    dot.edge('E', 'F3', label='3')
    dot.edge('E', 'F4', label='4')
    dot.edge('F1', 'C', label='Insertar un valor')
    dot.edge('F2', 'C', label='Buscar un valor')
    dot.edge('F3', 'C', label='Mostrar (los primeros 9)')
    dot.edge('F4', 'G', label='Cerrar programa')
    dot.edge('C', 'G', label='No')

    dot.render('main_flowchart', format='png')

if __name__ == "__main__":
    create_main_flowchart()

