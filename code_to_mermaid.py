from mermaid_objects import Node, Flowchart
import os
global SCRIPT_ROOT

class Stack:
    def __init__(self):
        self.stk = []

    def push(self, val):
        self.stk.append(val)

    def pop(self):
        return self.stk.pop()   

    def is_empty(self):
        return not bool(len(self.stk))

    def get_top(self):
        return self.stk[-1]

def perform_shunting_yard(text_contents) -> Flowchart:
    flowchart = Flowchart()
    stack = Stack()

    for text_line in text_contents:
        tabspaces = text_line.rstrip().count('\t')
        text_line = text_line.strip()

        if len(text_line) < 1: 
            continue

        node = Node(content = text_line, tabspace = tabspaces)
        flowchart.addNodes(node)
        if stack.is_empty():
            stack.push(node)
        else:
            while not stack.is_empty():
                if node.tabspace > stack.get_top().tabspace:
                    flowchart.connections.append((stack.get_top(), node))
                    stack.push(node)
                    break
                else:
                    stack.pop()
            else: stack.push(node)


    return flowchart

def flowchart_to_mermaid(flowchart) -> str:
    mermaid_code = None
    with open(os.path.join('mermaid_template.txt'), 'r') as file_handle:
        mermaid_code = file_handle.readlines()

    if mermaid_code is None or len(mermaid_code) < 1: 
        raise Exception("Cannot Read Mermaid Template Code")
    
    mermaid_nodes = []
    for node in flowchart.nodes:
        mermaid_nodes.append("{node_id}(\"{node_content}\")\n".format(node_id = node.nodeId, node_content = node.content))
    node_index = mermaid_code.index("%% Nodes\n")

    mermaid_code = mermaid_code[:node_index + 1] + mermaid_nodes + mermaid_code[node_index + 1:]

    mermaid_connections = []
    for connection in flowchart.connections:
        mermaid_connections.append("{source_node_id} --> {destination_node_id}\n".format(
            source_node_id = connection[0].nodeId, 
            destination_node_id = connection[1].nodeId)
        )
    
    edge_index = mermaid_code.index("%% Edges\n")

    mermaid_code = mermaid_code[:edge_index + 1] + mermaid_connections + mermaid_code[edge_index + 1:]

    return mermaid_code
    
    