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

    def get(self, key: int) -> int:
        if key not in self.node_map:
            return -1
        node = self.node_map[key]

        node.prev.next = node.next
        node.next.prev = node.prev

        node.next = self.head.next
        node.next.prev = node
        node.prev = self.head
        self.head.next = node

        return node.value

    def put(self, key: int, value: int) -> None:
        node = None
        if key in self.node_map:
            node = self.node_map[key]
            node.prev.next = node.next
            node.next.prev = node.prev
            node.value = value
            self.size -= 1
        else:
            node = Node(key, value)
            self.node_map[key] = node
        
        if self.size == self.capacity:
            node_to_delete = self.tail.prev
            node_to_delete.prev.next = node_to_delete.next
            node_to_delete.next.prev = node_to_delete.prev
            self.node_map.pop(node_to_delete.key)
            self.size -= 1
        
        node.prev = self.head
        node.next = self.head.next
        self.head.next = node
        node.next.prev = node
        self.size += 1
