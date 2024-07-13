import uuid

class Node:
    def __init__(self, content = "", tabspace = 0):
        self.content = content
        self.children = []
        self.nodeId = uuid.uuid4().hex
        self.tabspace = tabspace

class Flowchart:
    def __init__(self):
        self.nodes = []
        self.connections = []

    def addNodes(self, node):
        self.nodes.append(node)

    def addConnection(self, connection):
        self.connections.append(connection)

