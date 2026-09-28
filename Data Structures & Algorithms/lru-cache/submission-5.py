class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.node_map = dict()
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def __insert(self, after_node: Node, node: Node):
        node.next = after_node.next
        node.next.prev = node
        after_node.next = node
        node.prev = after_node
    
    def __delete(self, node: Node):
        node.next.prev = node.prev
        node.prev.next = node.next

    def get(self, key: int) -> int:
        if key not in self.node_map:
            return -1
        
        node = self.node_map[key]
        self.__delete(node)
        self.__insert(self.head, node)

        return node.value

    def put(self, key: int, value: int) -> None:
        node = None
        if key in self.node_map:
            node = self.node_map[key]
            self.__delete(node)
            node.value = value
            self.size -= 1
        else:
            node = Node(key, value)
            self.node_map[key] = node
        
        if self.size == self.capacity:
            node_to_delete = self.tail.prev
            self.__delete(node_to_delete)
            self.node_map.pop(node_to_delete.key)
            self.size -= 1
        
        self.__insert(self.head, node)
        self.size += 1
